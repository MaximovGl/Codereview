/*
Программа читает арифметическое выражение из файла, строит синтаксическое дерево,
вычисляет его значение при заданном x, преобразует дерево (заменяет A+x на x+A),
и выводит результаты в файл: результат вычисления, дерево в префиксной, постфиксной
и инфиксной форме с избыточными скобками.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <cctype>
#include <stdexcept>
#include <cmath>
#include <string>
#include <clocale>
#include <locale>
using namespace std;

// Установка русской локали для корректного отображения сообщений
void setRussianLocale() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    locale::global(locale("ru_RU.UTF-8"));
    wcout.imbue(locale("ru_RU.UTF-8"));
    wcerr.imbue(locale("ru_RU.UTF-8"));
}

// Структура узла дерева выражения
struct Node {
    string token;
    Node* left;
    Node* right;
};

// Функция токенизации входной строки
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
            throw runtime_error("Недопустимый символ: " + string(1, expr[i]));
        }
    }
    return tokens;
}

// Функция преобразования инфиксной записи в постфиксную (Обратная польская запись)
vector<string> infixToPostfix(const vector<string>& tokens) {
    stack<string> opStack;
    vector<string> output;
    map<string, int> precedence = {
        {"^", 4},
        {"*", 3}, {"/", 3}, {"%", 3},
        {"+", 2}, {"-", 2}
    };

    auto isRightAssociative = [](const string& op) {
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
                throw runtime_error("Непарные скобки");
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
            throw runtime_error("Непарные скобки");
        }
        output.push_back(opStack.top());
        opStack.pop();
    }

    return output;
}

// Построение дерева выражения из постфиксной записи
Node* buildTree(const vector<string>& postfix) {
    stack<Node*> st;
    for (const string& token : postfix) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "^") {
            Node* node = new Node{ token, nullptr, nullptr };
            if (st.size() < 2) {
                throw runtime_error("Недостаточно операндов для оператора: " + token);
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
        throw runtime_error("Неверная структура выражения");
    }
    return st.top();
}

// Вычисление значения выражения
int evaluate(Node* root, int x_value) {
    if (!root) {
        throw runtime_error("Пустое дерево при вычислении");
    }

    if (root->token == "x") {
        return x_value;
    }

    if (isdigit(static_cast<unsigned char>(root->token[0]))) {
        int num = stoi(root->token);
        if (num < 1 || num > 30) {
            throw runtime_error("Число вне диапазона [1,30]: " + root->token);
        }
        return num;
    }

    int leftVal = evaluate(root->left, x_value);
    int rightVal = evaluate(root->right, x_value);

    if (root->token == "+") return leftVal + rightVal;
    if (root->token == "-") return leftVal - rightVal;
    if (root->token == "*") return leftVal * rightVal;
    if (root->token == "/") {
        if (rightVal == 0) throw runtime_error("Деление на ноль");
        return leftVal / rightVal;
    }
    if (root->token == "%") {
        if (rightVal == 0) throw runtime_error("Деление по модулю на ноль");
        return leftVal % rightVal;
    }
    if (root->token == "^") {
        if (rightVal < 0) throw runtime_error("Отрицательный показатель степени недопустим");
        return static_cast<int>(pow(leftVal, rightVal));
    }

    throw runtime_error("Неизвестный оператор: " + root->token);
}

// Преобразование дерева: замена A+x на x+A
void transformTree(Node* root) {
    if (!root) return;
    transformTree(root->left);
    transformTree(root->right);
    if (root->token == "+" && root->right && root->right->token == "x") {
        swap(root->left, root->right);
    }
}

// Вывод дерева в префиксной форме
void printPrefix(Node* root, ofstream& fout) {
    if (!root) return;
    fout << root->token << " ";
    printPrefix(root->left, fout);
    printPrefix(root->right, fout);
}

// Вывод дерева в постфиксной форме
void printPostfix(Node* root, ofstream& fout) {
    if (!root) return;
    printPostfix(root->left, fout);
    printPostfix(root->right, fout);
    fout << root->token << " ";
}

// Вывод дерева в инфиксной форме с избыточными скобками
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

// Освобождение памяти дерева
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    setRussianLocale();

    string inputFile, outputFile;
    int x_value;

    // Ввод путей к файлам и значения x
    wcout << L"Введите путь к входному файлу: ";
    getline(cin, inputFile);
    wcout << L"Введите путь к выходному файлу: ";
    getline(cin, outputFile);
    wcout << L"Введите значение переменной x: ";
    cin >> x_value;

    // Чтение входного файла
    ifstream fin(inputFile);
    if (!fin.is_open()) {
        wcerr << L"Ошибка открытия файла: " << inputFile.c_str() << endl;
        return 1;
    }

    string expression;
    getline(fin, expression);
    fin.close();

    try {
        // Парсинг и построение дерева
        vector<string> tokens = tokenize(expression);
        vector<string> postfix = infixToPostfix(tokens);
        Node* root = buildTree(postfix);

        // Вычисление результата
        int result = evaluate(root, x_value);
        wcout << L"Результат вычисления: " << result << endl;

        // Преобразование дерева
        transformTree(root);

        // Запись результатов в выходной файл
        ofstream fout(outputFile);
        if (!fout.is_open()) {
            wcerr << L"Ошибка открытия файла: " << outputFile.c_str() << endl;
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

        wcout << L"Результаты успешно записаны в файл: " << outputFile.c_str() << endl;
    }
    catch (const exception& e) {
        wcerr << L"Ошибка: " << e.what() << endl;
        return 1;
    }

    // Пауза для Visual Studio
    wcout << L"Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}