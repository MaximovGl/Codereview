/**
 * @file expression_tree.cpp
 * @brief Реализация функций для работы с деревьями выражений
 *
 * Содержит реализацию функций, объявленных в expression_tree.h.
 */

#include "expression_tree.h"
#include <vector>
#include <stack>
#include <map>
#include <cctype>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <functional>

using namespace std;

vector<string> tokenize(const string& expr) {
    vector<string> tokens;
    int i = 0;
    while (i < expr.size()) {
        if (isspace(static_cast<unsigned char>(expr[i]))) {
            i++;
            continue;
        }
        if (isdigit(static_cast<unsigned char>(expr[i]))) {
            string num;
            while (i < expr.size() && isdigit(static_cast<unsigned char>(expr[i]))) {
                num += expr[i];
                i++;
            }
            tokens.push_back(num);
        }
        else if (expr[i] == 'x') {
            tokens.push_back("x");
            i++;
        }
        else if (string("+-*/%^()").find(expr[i]) != string::npos) {
            tokens.push_back(string(1, expr[i]));
            i++;
        }
        else {
            cerr << "Ошибка: недопустимый символ: " << expr[i] << endl;
            return {};
        }
    }
    return tokens;
}

vector<string> infixToPostfix(const vector<string>& tokens) {
    stack<string> opStack;
    vector<string> output;
    map<string, int> precedence = {
        {"^", 4},
        {"*", 3}, {"/", 3}, {"%", 3},
        {"+", 2}, {"-", 2}
    };

    function<bool(const string&)> isRightAssociative = [](const string& op) {
        return op == "^";
        };

    for (const string& token : tokens) {
        if (token == "(") {
            opStack.push(token);
        }
        else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                output.push_back(opStack.top());
                opStack.pop();
            }
            if (opStack.empty()) {
                cerr << "Ошибка: непарные скобки" << endl;
                return {};
            }
            opStack.pop();
        }
        else if (precedence.count(token)) {
            while (!opStack.empty() && opStack.top() != "(") {
                const string& topOp = opStack.top();
                if (precedence.at(topOp) > precedence.at(token) ||
                    (precedence.at(topOp) == precedence.at(token) && !isRightAssociative(token))) {
                    output.push_back(topOp);
                    opStack.pop();
                }
                else {
                    break;
                }
            }
            opStack.push(token);
        }
        else {
            output.push_back(token);
        }
    }

    while (!opStack.empty()) {
        if (opStack.top() == "(") {
            cerr << "Ошибка: непарные скобки" << endl;
            return {};
        }
        output.push_back(opStack.top());
        opStack.pop();
    }

    return output;
}

Node* buildTree(const vector<string>& postfix) {
    stack<Node*> st;
    for (const string& token : postfix) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "^") {
            Node* node = new Node{ token, nullptr, nullptr };
            if (st.size() < 2) {
                cerr << "Ошибка: недостаточно операндов для оператора: " << token << endl;
                return nullptr;
            }
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
            st.push(node);
        }
        else {
            st.push(new Node{ token, nullptr, nullptr });
        }
    }
    if (st.size() != 1) {
        cerr << "Ошибка: неверная структура выражения" << endl;
        return nullptr;
    }
    return st.top();
}

int evaluate(Node* root, int x_value) {
    if (!root) {
        cerr << "Ошибка: пустое дерево при вычислении" << endl;
        return 0;
    }

    if (root->token == "x") {
        return x_value;
    }

    if (isdigit(static_cast<unsigned char>(root->token[0]))) {
        int num = stoi(root->token);
        if (num < 1 || num > 30) {
            cerr << "Ошибка: число вне диапазона [1,30]: " << root->token << endl;
            return 0;
        }
        return num;
    }

    int leftVal = evaluate(root->left, x_value);
    int rightVal = evaluate(root->right, x_value);

    if (root->token == "+") return leftVal + rightVal;
    if (root->token == "-") return leftVal - rightVal;
    if (root->token == "*") return leftVal * rightVal;
    if (root->token == "/") {
        if (rightVal == 0) {
            cerr << "Ошибка: деление на ноль" << endl;
            return 0;
        }
        return leftVal / rightVal;
    }
    if (root->token == "%") {
        if (rightVal == 0) {
            cerr << "Ошибка: деление по модулю на ноль" << endl;
            return 0;
        }
        return leftVal % rightVal;
    }
    if (root->token == "^") {
        if (rightVal < 0) {
            cerr << "Ошибка: отрицательный показатель степени недопустим" << endl;
            return 0;
        }
        return static_cast<int>(pow(leftVal, rightVal));
    }

    cerr << "Ошибка: неизвестный оператор: " << root->token << endl;
    return 0;
}

void transformTree(Node* root) {
    if (!root) return;
    transformTree(root->left);
    transformTree(root->right);
    if (root->token == "+" && root->right && root->right->token == "x") {
        swap(root->left, root->right);
    }
}

void printPrefix(Node* root, ofstream& fout) {
    if (!root) return;
    fout << root->token << " ";
    printPrefix(root->left, fout);
    printPrefix(root->right, fout);
}

void printPostfix(Node* root, ofstream& fout) {
    if (!root) return;
    printPostfix(root->left, fout);
    printPostfix(root->right, fout);
    fout << root->token << " ";
}

void printInfix(Node* root, ofstream& fout) {
    if (!root) return;
    if (!root->left && !root->right) {
        fout << root->token;
    }
    else {
        fout << "(";
        printInfix(root->left, fout);
        fout << root->token;
        printInfix(root->right, fout);
        fout << ")";
    }
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int processExpression(const string& expression, int x_value, const string& outputFile) {
    vector<string> tokens = tokenize(expression);
    if (tokens.empty()) {
        cerr << "Ошибка: не удалось разбить выражение на токены" << endl;
        return 1;
    }

    vector<string> postfix = infixToPostfix(tokens);
    if (postfix.empty()) {
        cerr << "Ошибка: не удалось преобразовать в постфиксную форму" << endl;
        return 1;
    }

    Node* root = buildTree(postfix);
    if (!root) {
        cerr << "Ошибка: не удалось построить дерево выражения" << endl;
        return 1;
    }

    int result = evaluate(root, x_value);
    if (result == 0) {
        cerr << "Ошибка: вычисление дало нулевой результат" << endl;
        deleteTree(root);
        return 1;
    }

    transformTree(root);

    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cerr << "Ошибка открытия файла: " << outputFile << endl;
        deleteTree(root);
        return 1;
    }

    fout << "Результат: " << result << "\n\n";
    fout << "Префиксная форма: ";
    printPrefix(root, fout);
    fout << "\n\nПостфиксная форма: ";
    printPostfix(root, fout);
    fout << "\n\nИнфиксная форма с скобками: ";
    printInfix(root, fout);
    fout << endl;

    fout.close();
    deleteTree(root);

    return 0;
}