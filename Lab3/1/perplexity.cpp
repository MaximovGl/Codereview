
#include <iostream>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    // ���� ����� �� ������������
    cout << "������� �����: ";
    string word;
    cin >> word;

    // �������� �� ������ ����
    if (word.empty()) {
        cerr << "������: ������� ������ ������." << endl;
        return 1;
    }

    // ������������� ���������� ��������� �����
    random_device rd;
    mt19937 generator(rd());

    string shuffled_word = word;
    int attempts = 0;

    // ������ ������������ (�� ������� �������� �����)
    do {
        // ������������� ���� � �����
        shuffle(shuffled_word.begin(), shuffled_word.end(), generator);

        // ����� ���������� �������������
        cout << shuffled_word << " ";
        attempts++;

    } while (shuffled_word != word);  // ������� ���������

    // ����� ��������� ����������
    cout << endl << attempts << " �������." << endl;

    return 0;
}