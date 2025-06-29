/**
 * @file word_shuffler.cpp
 * @brief Реализация функции перемешивания букв в слове
 */

#include "word_shuffler.h"  
#include <iostream>
#include <random>
#include <algorithm>
#include <stdexcept>

using namespace std;

int shuffle_until_original(const string& word) {
    if (word.empty()) {
        cerr << "Ошибка: введена пустая строка";
    }

    random_device rd;
    mt19937 generator(rd());

    string shuffled = word;
    int count = 0;

    do {
        shuffle(shuffled.begin(), shuffled.end(), generator);
        count++;
        cout << shuffled << endl;
    } while (shuffled != word);

    return count;
}