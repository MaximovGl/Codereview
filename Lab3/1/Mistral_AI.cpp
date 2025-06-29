#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

//Mistral AI

using namespace std;

/* ��������� ��� ������������ ���� � ����� �� ���������� � �������� ������ */

int main() {
    string word;
    cout << "������� �����: ";
    cin >> word;

    string original_word = word;
    int attempts = 0;

    // ���������� ��������� ��������� �����
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 g(seed);

    do {
        // ������������ ����� � �����
        shuffle(word.begin(), word.end(), g);
        cout << word << endl;
        attempts++;
    } while (word != original_word);

    cout << attempts << " �������" << endl;

    return 0;
}