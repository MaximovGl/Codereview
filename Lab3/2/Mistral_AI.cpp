/*
CalcTree9. В текстовом файле с именем FN1 дано арифметическое выражение в инфиксной форме.
В выражении могут использоваться операции: сложение(+), вычитание(-), умножение(*),
деление нацело(/), остаток от деления(%), возведение в степень(^), а так же целые числа из
промежутка [1; 30] и переменная x. Для операции возведения в степень показатель степени -
неотрицательное целое число. Постройте дерево выражения. После этого вычислите значение
выражения при заданном значении переменной x и выведите результат в текстовый файл с именем FN2.
Преобразуйте дерево, заменив все поддеревья вида A+x на x+A, где A - некоторое поддерево, а x -
переменная. Распечатайте дерево после преобразования в файл FN2 в префиксной и постфиксной форме,
а так же в инфиксной форме с избыточными скобками. При наличии несколько подряд идущих одинаковых
операций дерево должно строиться по правилу: операции одинакового приоритета вычисляются по порядку
слева направо. Результаты всех вычислений, включая промежуточные, принадлежат типу int.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <cctype>
#include <stdexcept>

using namespace std;

// Узел дерева выражения
struct Node {
    string value; // значение узла
    Node* left;   // левый потомок
    Node* right;  // правый потомок

    Node(string val) : value(val), left(nullptr), right(nullptr) {}
};

// Класс для построения и обработки дерева выражения
class ExpressionTree {
private:
    Node* root;

    // Вспомогательная функция для освобождения памяти дерева
    void deleteTree(Node* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    // Вспомогательная функция для проверки, является ли строка числом
    bool isNumber(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    // Вспомогательная функция для проверки, находится ли число в диапазоне [1, 30]
    bool isNumberInRange(const string& s) {
        if (!isNumber(s)) return false;
        int num = stoi(s);
        return num >= 1 && num <= 30;
    }

    // Вспомогательная функция для проверки, является ли строка переменной x
    bool isVariable(const string& s) {
        return s == "x";
    }

    // Вспомогательная функция для проверки, является ли строка оператором
    bool isOperator(const string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/" || s == "%" || s == "^";
    }

    // Функция для получения приоритета оператора
    int getPriority(const string& op) {
        if (op == "^") return 4;
        if (op == "*" || op == "/" || op == "%") return 3;
        if (op == "+" || op == "-") return 2;
        return 0;
    }

    // Функция для построения дерева выражения из постфиксной формы
    Node* buildTree(const vector<string>& postfix) {
        stack<Node*> st;
        for (const string& token : postfix) {
            if (isNumber(token) || isVariable(token)) {
                st.push(new Node(token));
            }
            else if (isOperator(token)) {
                Node* right = st.top(); st.pop();
                Node* left = st.top(); st.pop();
                Node* node = new Node(token);
                node->left = left;
                node->right = right;
                st.push(node);
            }
        }
        return st.top();
    }

    // Функция для преобразования инфиксной формы в постфиксную (Обратная польская нотация)
    vector<string> infixToPostfix(const vector<string>& infix) {
        vector<string> postfix;
        stack<string> st;
        for (const string& token : infix) {
            if (isNumber(token) || isVariable(token)) {
                postfix.push_back(token);
            }
            else if (isOperator(token)) {
                while (!st.empty() && getPriority(st.top()) >= getPriority(token)) {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(token);
            }
            else if (token == "(") {
                st.push(token);
            }
            else if (token == ")") {
                while (!st.empty() && st.top() != "(") {
                    postfix.push_back(st.top());
                    st.pop();
                }
                if (st.empty()) {
                    throw runtime_error("Mismatched parentheses");
                }
                st.pop(); // Удаляем "(" из стека
            }
        }
        while (!st.empty()) {
            if (st.top() == "(") {
                throw runtime_error("Mismatched parentheses");
            }
            postfix.push_back(st.top());
            st.pop();
        }
        return postfix;
    }

    // Функция для токенизации входной строки
    vector<string> tokenize(const string& expr) {
        vector<string> tokens;
        string token;
        for (size_t i = 0; i < expr.size(); ++i) {
            char c = expr[i];
            if (isspace(c)) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
            }
            else if (c == '(' || c == ')') {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
                tokens.push_back(string(1, c));
            }
            else if (isOperator(string(1, c))) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
                // Проверка на унарный оператор (например, отрицательное число)
                if (c == '-' && (i == 0 || expr[i - 1] == '(' || isOperator(string(1, expr[i - 1])))) {
                    // Обработка унарного минуса (но в задаче числа должны быть положительными)
                    throw runtime_error("Negative numbers are not allowed");
                }
                tokens.push_back(string(1, c));
            }
            else {
                token += c;
            }
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
        return tokens;
    }

    // Функция для проверки корректности токенов
    void validateTokens(const vector<string>& tokens) {
        for (const string& token : tokens) {
            if (isNumber(token)) {
                if (!isNumberInRange(token)) {
                    throw runtime_error("Number out of range [1, 30]: " + token);
                }
            }
        }
    }

    // Функция для вычисления значения выражения
    int evaluate(Node* node, int x) {
        if (node == nullptr) return 0;
        if (isNumber(node->value)) {
            return stoi(node->value);
        }
        else if (isVariable(node->value)) {
            return x;
        }
        else {
            int leftVal = evaluate(node->left, x);
            int rightVal = evaluate(node->right, x);
            if (node->value == "+") return leftVal + rightVal;
            if (node->value == "-") return leftVal - rightVal;
            if (node->value == "*") return leftVal * rightVal;
            if (node->value == "/") {
                if (rightVal == 0) throw runtime_error("Division by zero");
                return leftVal / rightVal;
            }
            if (node->value == "%") {
                if (rightVal == 0) throw runtime_error("Modulo by zero");
                return leftVal % rightVal;
            }
            if (node->value == "^") {
                if (rightVal < 0) throw runtime_error("Negative exponent");
                int result = 1;
                for (int i = 0; i < rightVal; ++i) {
                    result *= leftVal;
                }
                return result;
            }
        }
        return 0;
    }

    // Функция для преобразования дерева
    void transformTree(Node* node) {
        if (node == nullptr) return;
        transformTree(node->left);
        transformTree(node->right);
        if (node->value == "+" && node->right != nullptr && isVariable(node->right->value)) {
            // Проверяем, что левый узел - это не просто переменная x (чтобы избежать дублирования x + x)
            if (!(node->left != nullptr && isVariable(node->left->value))) {
                Node* temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
        }
    }

    // Функция для печати дерева в префиксной форме
    void printPrefix(Node* node, ostream& os) {
        if (node == nullptr) return;
        os << node->value << " ";
        printPrefix(node->left, os);
        printPrefix(node->right, os);
    }

    // Функция для печати дерева в постфиксной форме
    void printPostfix(Node* node, ostream& os) {
        if (node == nullptr) return;
        printPostfix(node->left, os);
        printPostfix(node->right, os);
        os << node->value << " ";
    }

    // Функция для печати дерева в инфиксной форме с избыточными скобками
    void printInfix(Node* node, ostream& os) {
        if (node == nullptr) return;
        if (isOperator(node->value)) {
            os << "( ";
            printInfix(node->left, os);
            os << node->value << " ";
            printInfix(node->right, os);
            os << ") ";
        }
        else {
            os << node->value << " ";
        }
    }

public:
    ExpressionTree(const string& expr) {
        vector<string> infix = tokenize(expr);
        validateTokens(infix);
        vector<string> postfix = infixToPostfix(infix);
        root = buildTree(postfix);
    }

    ~ExpressionTree() {
        deleteTree(root);
    }

    int evaluate(int x) {
        return evaluate(root, x);
    }

    void transform() {
        transformTree(root);
    }

    void printPrefix(ostream& os) {
        printPrefix(root, os);
        os << endl;
    }

    void printPostfix(ostream& os) {
        printPostfix(root, os);
        os << endl;
    }

    void printInfix(ostream& os) {
        printInfix(root, os);
        os << endl;
    }
};

int main() {
    string fn1, fn2;
    int x;

    // Запрос имени входного файла у пользователя
    cout << "Enter the input file name (FN1): ";
    cin >> fn1;

    // Запрос имени выходного файла у пользователя
    cout << "Enter the output file name (FN2): ";
    cin >> fn2;

    // Запрос значения переменной x у пользователя
    cout << "Enter the value of x (must be in range [1, 30]): ";
    cin >> x;

    // Проверка диапазона значения x
    if (x < 1 || x > 30) {
        cerr << "Error: x value out of range. It should be in [1, 30]." << endl;
        return 1;
    }

    ifstream inFile(fn1);
    if (!inFile) {
        cerr << "Error opening input file: " << fn1 << endl;
        return 1;
    }

    string expr;
    getline(inFile, expr); // Чтение первой строки файла
    inFile.close();

    try {
        ExpressionTree tree(expr);
        int result = tree.evaluate(x);

        tree.transform();

        ofstream outFile(fn2);
        if (!outFile) {
            cerr << "Error opening output file: " << fn2 << endl;
            return 1;
        }

        outFile << "Result: " << result << endl;
        outFile << "Prefix form: ";
        tree.printPrefix(outFile);
        outFile << "Postfix form: ";
        tree.printPostfix(outFile);
        outFile << "Infix form with redundant parentheses: ";
        tree.printInfix(outFile);

        outFile.close();

        cout << "Program executed successfully. Results are written to " << fn2 << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}