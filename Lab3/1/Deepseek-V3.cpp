/*
Программа вводит слово с клавиатуры, затем случайным образом переставляет буквы в слове.
Процесс перестановки продолжается до тех пор, пока полученное слово не совпадёт с исходным.
После каждой перестановки выводится текущий вариант слова. В конце выводится общее количество
попыток (количество перестановок, включая последнюю, которая вернула исходное слово).
*/

#include <iostream>
#include <string>
#include <random>
#include <algorithm>

//Дипсик

using namespace std;

int main() {
    string word;
    cout << "Введите слово: ";
    cin >> word;

    // Проверка на пустой ввод
    if (word.empty()) {
        cerr << "Ошибка: введена пустая строка." << endl;
        return 1;
    }

    // Инициализация генератора случайных чисел
    random_device rd;
    mt19937 generator(rd());

    string shuffled = word;
    int count = 0;

    do {
        // Перемешиваем буквы в слове
        shuffle(shuffled.begin(), shuffled.end(), generator);
        count++;
        cout << shuffled << endl;
    } while (shuffled != word);

    cout << count << " попыток" << endl;

    return 0;
}