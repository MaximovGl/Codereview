/* CalcTree9: Построение и преобразование дерева арифметического выражения */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <stdexcept>
#include <memory>
#include <typeinfo>
#include <algorithm>

using namespace std;

// Классы узлов дерева выражения
class Node {
public:
    virtual ~Node() = default;
    virtual int evaluate(int x) const = 0;
    virtual string toPrefix() const = 0;
    virtual string toPostfix() const = 0;
    virtual string toInfix() const = 0;
    virtual unique_ptr<Node> clone() const = 0;
    virtual void transform() = 0;
};

class NumberNode : public Node {
    int value;
public:
    explicit NumberNode(int v) : value(v) {}
    int evaluate(int) const override { return value; }
    string toPrefix() const override { return to_string(value); }
    string toPostfix() const override { return to_string(value); }
    string toInfix() const override { return to_string(value); }
    unique_ptr<Node> clone() const override {
        return make_unique<NumberNode>(value);
    }
    void transform() override {}
};

class VariableNode : public Node {
public:
    int evaluate(int x) const override { return x; }
    string toPrefix() const override { return "x"; }
    string toPostfix() const override { return "x"; }
    string toInfix() const override { return "x"; }
    unique_ptr<Node> clone() const override {
        return make_unique<VariableNode>();
    }
    void transform() override {}
};

class BinaryOpNode : public Node {
    char op;
    unique_ptr<Node> left;
    unique_ptr<Node> right;
public:
    BinaryOpNode(char op, unique_ptr<Node> l, unique_ptr<Node> r)
        : op(op), left(move(l)), right(move(r)) {
    }

    int evaluate(int x) const override {
        int leftVal = left->evaluate(x);
        int rightVal = right->evaluate(x);

        switch (op) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': {
            if (rightVal == 0) throw runtime_error("Division by zero");
            return leftVal / rightVal;
        }
        case '%': {
            if (rightVal == 0) throw runtime_error("Modulo by zero");
            return leftVal % rightVal;
        }
        case '^': {
            if (rightVal < 0) throw runtime_error("Negative exponent");
            if (rightVal == 0) return 1;
            int result = 1;
            int base = leftVal;
            int exp = rightVal;
            while (exp) {
                if (exp & 1) result *= base;
                exp >>= 1;
                base *= base;
            }
            return result;
        }
        default: throw runtime_error("Unknown operator");
        }
    }

    string toPrefix() const override {
        return string(1, op) + " " + left->toPrefix() + " " + right->toPrefix();
    }

    string toPostfix() const override {
        return left->toPostfix() + " " + right->toPostfix() + " " + string(1, op);
    }

    string toInfix() const override {
        return "(" + left->toInfix() + " " + op + " " + right->toInfix() + ")";
    }

    unique_ptr<Node> clone() const override {
        return make_unique<BinaryOpNode>(op, left->clone(), right->clone());
    }

    void transform() override {
        left->transform();
        right->transform();
        if (op == '+' && typeid(*right) == typeid(VariableNode)) {
            swap(left, right);
        }
    }
};

// Вспомогательные функции
vector<string> tokenize(const string& expr) {
    vector<string> tokens;
    for (size_t i = 0; i < expr.size(); ) {
        if (isspace(expr[i])) {
            i++;
            continue;
        }
        if (isdigit(expr[i])) {
            string num;
            while (i < expr.size() && isdigit(expr[i])) {
                num += expr[i];
                i++;
            }
            tokens.push_back(num);
        }
        else if (expr[i] == 'x') {
            tokens.emplace_back("x");
            i++;
        }
        else if (string("+-*/%^()").find(expr[i]) != string::npos) {
            tokens.push_back(string(1, expr[i]));
            i++;
        }
        else {
            throw runtime_error("Invalid character: " + string(1, expr[i]));
        }
    }
    return tokens;
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

vector<string> infixToPostfix(const vector<string>& tokens) {
    vector<string> output;
    stack<string> opStack;

    for (const string& token : tokens) {
        if (isdigit(token[0]) || token == "x") {
            output.push_back(token);
        }
        else if (token == "(") {
            opStack.push(token);
        }
        else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                output.push_back(opStack.top());
                opStack.pop();
            }
            if (opStack.empty()) throw runtime_error("Mismatched parentheses");
            opStack.pop();
        }
        else {
            char op = token[0];
            while (!opStack.empty() && opStack.top() != "(" &&
                precedence(opStack.top()[0]) >= precedence(op)) {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
    }

    while (!opStack.empty()) {
        if (opStack.top() == "(") throw runtime_error("Mismatched parentheses");
        output.push_back(opStack.top());
        opStack.pop();
    }

    return output;
}

unique_ptr<Node> buildTree(const vector<string>& postfix) {
    stack<unique_ptr<Node>> nodeStack;

    for (const string& token : postfix) {
        if (isdigit(token[0])) {
            int num = stoi(token);
            if (num < 1 || num > 30) {
                throw runtime_error("Number out of range [1,30]: " + token);
            }
            nodeStack.push(make_unique<NumberNode>(num));
        }
        else if (token == "x") {
            nodeStack.push(make_unique<VariableNode>());
        }
        else {
            if (nodeStack.size() < 2) {
                throw runtime_error("Not enough operands for operator " + token);
            }
            unique_ptr<Node> right = move(nodeStack.top());
            nodeStack.pop();
            unique_ptr<Node> left = move(nodeStack.top());
            nodeStack.pop();
            nodeStack.push(
                make_unique<BinaryOpNode>(token[0], move(left), move(right))
            );
        }
    }

    if (nodeStack.size() != 1) throw runtime_error("Invalid expression");
    return move(nodeStack.top());
}

int main() {
    try {
        // Чтение выражения из файла
        ifstream fin("FN1.txt");
        if (!fin) throw runtime_error("Cannot open FN1.txt");
        string expr;
        getline(fin, expr);
        fin.close();

        // Построение AST
        vector<string> tokens = tokenize(expr);
        vector<string> postfix = infixToPostfix(tokens);
        unique_ptr<Node> root = buildTree(postfix);

        // Ввод значения переменной
        int x_val;
        cout << "Enter value for x: ";
        cin >> x_val;

        // Вычисление результата
        int result = root->evaluate(x_val);

        // Преобразование дерева
        unique_ptr<Node> transformed = root->clone();
        transformed->transform();

        // Запись результатов в файл
        ofstream fout("FN2.txt");
        fout << "Result: " << result << "\n\n";
        fout << "Transformed tree:\n";
        fout << "Prefix: " << transformed->toPrefix() << "\n";
        fout << "Postfix: " << transformed->toPostfix() << "\n";
        fout << "Infix: " << transformed->toInfix() << endl;
        fout.close();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}