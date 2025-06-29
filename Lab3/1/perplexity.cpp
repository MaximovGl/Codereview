
#include <iostream>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    // Ввод слова от пользователя
    cout << "Введите слово: ";
    string word;
    cin >> word;

    // Проверка на пустой ввод
    if (word.empty()) {
        cerr << "Ошибка: введена пустая строка." << endl;
        return 1;
    }

    // Инициализация генератора случайных чисел
    random_device rd;
    mt19937 generator(rd());

    string shuffled_word = word;
    int attempts = 0;

    // Первая перестановка (не выводим исходное слово)
    do {
        // Перемешивание букв в слове
        shuffle(shuffled_word.begin(), shuffled_word.end(), generator);

        // Вывод результата перемешивания
        cout << shuffled_word << " ";
        attempts++;

    } while (shuffled_word != word);  // Условие остановки

    // Вывод итогового результата
    cout << endl << attempts << " попыток." << endl;

    return 0;
}