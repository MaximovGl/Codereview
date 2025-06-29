/**
 * @file CR3.2.cpp
 * @brief Главный модуль программы для обработки выражений
 */

#include "expression_tree.h"
#include <iostream>
#include <fstream>
#include <clocale>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    string inputFile, outputFile;
    int x_value;

    cout << "Введите путь к входному файлу: ";
    getline(cin, inputFile);
    cout << "Введите путь к выходному файлу: ";
    getline(cin, outputFile);
    cout << "Введите значение переменной x: ";
    cin >> x_value;

    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cerr << "Ошибка открытия файла: " << inputFile << endl;
        return 1;
    }

    string expression;
    getline(fin, expression);
    fin.close();

    int result = processExpression(expression, x_value, outputFile);

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return result;
}