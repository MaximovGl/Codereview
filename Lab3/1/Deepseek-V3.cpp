/*
��������� ������ ����� � ����������, ����� ��������� ������� ������������ ����� � �����.
������� ������������ ������������ �� ��� ���, ���� ���������� ����� �� ������� � ��������.
����� ������ ������������ ��������� ������� ������� �����. � ����� ��������� ����� ����������
������� (���������� ������������, ������� ���������, ������� ������� �������� �����).
*/

#include <iostream>
#include <string>
#include <random>
#include <algorithm>

//������

using namespace std;

int main() {
    string word;
    cout << "������� �����: ";
    cin >> word;

    // �������� �� ������ ����
    if (word.empty()) {
        cerr << "������: ������� ������ ������." << endl;
        return 1;
    }

    // ������������� ���������� ��������� �����
    random_device rd;
    mt19937 generator(rd());

    string shuffled = word;
    int count = 0;

    do {
        // ������������ ����� � �����
        shuffle(shuffled.begin(), shuffled.end(), generator);
        count++;
        cout << shuffled << endl;
    } while (shuffled != word);

    cout << count << " �������" << endl;

    return 0;
}