//FIXME задание не по формату
//К - ичные числа.Среди чисел в системе счисления с основанием K (2≤K≤10) определить сколько 
//имеется чисел из N(1 < N < 20, K + N < 26) разрядов таких, что в их записи не содержится 
//два и более подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
//представьте в виде вещественного числа.

#include "Count.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int main() {
    setlocale(LC_ALL, "ru");

    //FIXME Программа не работает даже на базовых тестах.

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


    int basis, dig_in_num;
    cout << "Введите систему счисления и кол-ов цифр в числе: ";
    cin >> basis >> dig_in_num;

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


    return 0;

}
