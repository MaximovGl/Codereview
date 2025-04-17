//�������� ����� N ����������.�������� ����(�i) � ��������� �����(di) �������.
//����� ������� ����� ������������ �������, ����� �� ��������� ��� �������� Z ��, � �� ����� 
//��������� ����� ��������� �����������.��������, ��� ������� �����������.�������
//���������� ������ �����, ������� ����� �����.�������� ������ ��������� � ��������� �����, 
//� ������ ������ ������� N � Z, � �� ������ ������ �������� �����(� ��), � ������� - ��������
//������ �� ������ �������.������� ��� �� ��������� ��� � ����� �������� ����������.

#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

void SelectArts(vector<vector<int>>& dp, int k, int s, vector<int>& weights, vector<int>& time) {
    if (k == 0 || s == 0)
        return;
    if (dp[k][s] == dp[k - 1][s]) {
        SelectArts(dp, k - 1, s, weights, time);
    }
    else {
        cout << k << ' ';
        SelectArts(dp, k - 1, s - weights[k], weights, time);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream input("1.1.txt");
    if (!input.is_open()) {
        cout << "������ ��� �������� �����" << endl;
        return 1;
    }

    int N, Z;
    input >> N >> Z;

    vector<int> weights(N + 1);
    vector<int> time(N + 1);

    for (int i = 1; i <= N; i++) {
        input >> weights[i];
    }

    for (int i = 1; i <= N; i++) {
        input >> time[i];
    }

    input.close();

    int max_weight = 0;
    for (int w : weights) {
        max_weight += w;
    }

    vector<vector<int>> dp(N + 1, vector<int>(max_weight + 1, 999));
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }

    for (int k = 1; k <= N; k++) {
        for (int s = 1; s <= max_weight; s++) {
            if (s >= weights[k] && dp[k - 1][s - weights[k]] != 999) {
                dp[k][s] = min(dp[k - 1][s], dp[k - 1][s - weights[k]] + time[k]);
            }
            else {
                dp[k][s] = dp[k - 1][s];
            }
        }
    }

    int min_time = 9999;
    int total_weight = 0;

    for (int s = Z + 1; s <= max_weight; s++) {
        if (dp[N][s] < min_time) {
            min_time = dp[N][s];
            total_weight = s;
        }
    }

    cout << "��������� ��������� -> ";
    SelectArts(dp, N, total_weight, weights, time);
    cout << endl;

    cout << "��������� ��� -> " << total_weight << " ��" << endl;
    cout << "����� ��������� ����� -> " << min_time << endl;

    return 0;
}