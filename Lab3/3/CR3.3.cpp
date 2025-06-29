/**
 * @file CR3.3.cpp
 * @brief Главный модуль для работы с графами
 */

#include <iostream>
#include <string>
#include "graph_utils.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string inputFile, outputFile;

    cout << "Введите имя входного файла: ";
    getline(cin, inputFile);

    cout << "Введите имя выходного файла: ";
    getline(cin, outputFile);

    if (processGraph(inputFile, outputFile)) {
        cout << "Матрица инцидентности успешно записана в файл: "
            << outputFile << endl;
        return 0;
    }
    else {
        cerr << "Ошибка при обработке графа" << endl;
        return 1;
    }
}