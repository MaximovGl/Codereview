#include "Count.h"
#include <iostream>
#include <limits>
#include <vector>
#include <climits>

using namespace std;

int Intcheck(const string& prompt) {
    int value = 0;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.good()) {
            return value;
        }
        else {
            cout << " Ошибка: Введите целое число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void CalculateNumbers(int basis, int dig_in_num) {
    //FIXME Программа не работает даже на базовых тестах.
    //FIXME не было проверки ввода.

    vector<vector<double>> nums_w_last_dig(dig_in_num + 1, 
        vector<double>(basis, 0));

    // Базовый случай: для чисел длины 1
    for (int digit = 0; digit < basis; ++digit) {
        nums_w_last_dig[1][digit] = 1;
    }

    // Для чисел длины 2 и более
    for (int length = 2; length <= dig_in_num; ++length) {
        // Для цифры 0: можно ставить только после ненулевых цифр
        for (int prev_digit = 1; prev_digit < basis; ++prev_digit) {
            nums_w_last_dig[length][0] += nums_w_last_dig[length - 1][prev_digit];
        }
        
        // Для ненулевых цифр: можно ставить после любой цифры
        for (int digit = 1; digit < basis; ++digit) {
            for (int prev_digit = 0; prev_digit < basis; ++prev_digit) {
                nums_w_last_dig[length][digit] += nums_w_last_dig[length - 1][prev_digit];
            }
        }
    }

    double result = 0;
    for (int digit = 0; digit < basis; ++digit) {
        result += nums_w_last_dig[dig_in_num][digit];
    }

    cout << "Ответ: " << result << endl;
}
