//К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько 
//имеется чисел из N(1 < N < 20, K + N < 26) разрядов таких, что в их записи не содержится 
//два и более подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
//представьте в виде вещественного числа.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");


    int K, N;
    cout << "Введите K и N: ";
    cin >> K >> N;

    vector<vector<double>> dp(N + 1, vector<double>(K, 0));

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


    return 0;
}