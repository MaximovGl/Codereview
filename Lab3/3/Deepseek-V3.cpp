/* ������: Graf2. ���������� ������� ������������� �� ������� ��������� ������������������ �����. */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // ��������� ������� ����
    ifstream inFile("FN1.txt");
    if (!inFile) {
        cerr << "������: �� ������� ������� FileName1.txt" << endl;
        return 1;
    }

    int n;
    inFile >> n;

    // ��������� ������� ���������
    vector<vector<int>> adjMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> adjMatrix[i][j];
        }
    }
    inFile.close();

    // �������� �������������� ������� ���������
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjMatrix[i][j] != adjMatrix[j][i]) {
                cerr << "������: ������� ��������� �� �����������" << endl;
                return 1;
            }
        }
    }

    // ������� ���������� ���� (������� �����������)
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (adjMatrix[i][j] != 0) {
                m++;
            }
        }
    }

    // �������� � ���������� ������� �������������
    vector<vector<int>> incMatrix(n, vector<int>(m, 0));
    int edgeIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (adjMatrix[i][j] != 0) {
                incMatrix[i][edgeIndex] = 1;
                if (i != j) {
                    incMatrix[j][edgeIndex] = 1;
                }
                edgeIndex++;
            }
        }
    }

    // ������ ���������� � �������� ����
    ofstream outFile("FileName2.txt");
    if (!outFile) {
        cerr << "������: �� ������� ������� FileName2.txt" << endl;
        return 1;
    }

    outFile << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            outFile << incMatrix[i][j];
            if (j < m - 1) {
                outFile << " ";
            }
        }
        outFile << endl;
    }
    outFile.close();

    return 0;
