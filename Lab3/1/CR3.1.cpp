/**
 * @file CR3.1.cpp
 * @brief Главный модуль для демонстрации работы перемешивателя слов
 */

#include <iostream>
#include <string>
#include "word_shuffler.h"  

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    string word;
    cout << "Введите слово: ";
    cin >> word;

    try {
        int attempts = shuffle_until_original(word);
        cout << "Потребовалось попыток: " << attempts << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}