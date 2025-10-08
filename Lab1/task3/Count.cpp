#include "Count.h"
#include <iostream>
#include <limits>
#include <vector>

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
            cin.clear(); // Сброс флагов ошибок ввода
            // Очистка буфера ввода до следующей новой строки
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void CalculateNumbers(int basis, int dig_in_num) {
    //FIXME Программа не работает даже на базовых тестах.
    //FIXME не было проверки ввода.

    /*vector<vector<double>> dp(N + 1, vector<double>(K, 0));

    for (int j = 0; j < K; ++j) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j < K; ++j) {
            dp[i][0] += dp[i - 1][j];
        }

        for (int j = 1; j < K; ++j) {
            for (int l = 0; l < K; ++l) {
                dp[i][j] += dp[i - 1][l];
            }
        }
    }

    double result = 0;
    for (int j = 1; j < K; ++j) {
        result += dp[N][j];
    }

    cout << "Ответ: " << result << endl;


    return 0;*/

    //FIXME однобуквенные переменные
    //int K, N;

    //FIXME однобуквенные переменные
    //vector<vector<double>> dp(dig_in_num + 1, vector<double>(basis, 0));
    vector<vector<double>> nums_w_last_dig(dig_in_num + 1,
        vector<double>(basis, 0)); //кол-во числел оканчивающихся данной конкретной цифрой 

    for (int digit = 0; digit < basis; ++digit) {
        nums_w_last_dig[1][digit] = 1;
    }

    for (int length = 2; length <= dig_in_num; ++length) {
        for (int digit = 0; digit < basis; ++digit) {
            nums_w_last_dig[length][digit] = 1;
        }
    }

    for (int length = 2; length <= dig_in_num; ++length) {
        for (int digit = 1; digit < basis; ++digit) {
            nums_w_last_dig[length][0] += nums_w_last_dig[length - 1][digit];
        }

        for (int digit = 1; digit < basis; ++digit) {
            for (int l = 0; l < basis; ++l) {
                nums_w_last_dig[length][digit]+=nums_w_last_dig[length-1][l];
            }
        }
    }

    double result = 0;
    for (int digit = 1; digit < basis; ++digit) {
        result += nums_w_last_dig[dig_in_num][digit];
    }

    cout << "Ответ: " << result +1 << endl;
}
