#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

//Mistral AI

using namespace std;

/* Программа для перестановки букв в слове до совпадения с исходным словом */

int main() {
    string word;
    cout << "Введите слово: ";
    cin >> word;

    string original_word = word;
    int attempts = 0;

    // Используем генератор случайных чисел
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 g(seed);

    do {
        // Перемешиваем буквы в слове
        shuffle(word.begin(), word.end(), g);
        cout << word << endl;
        attempts++;
    } while (word != original_word);

    cout << attempts << " попыток" << endl;

    return 0;
}