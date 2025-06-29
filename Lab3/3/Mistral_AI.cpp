#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

/* ����������� ������� �Graf2 */

int main() {
    // ��������� ������� ����
    ifstream inputFile("FN1.txt");
    if (!inputFile.is_open()) {
        throw runtime_error("�� ������� ������� ���� FileName1.txt");
    }

    int n;
    inputFile >> n;

    if (n <= 0) {
        throw runtime_error("���������� ������ ������ ���� ������������� ������");
    }

    // ������ ������� ���������
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(inputFile >> adjacencyMatrix[i][j])) {
                throw runtime_error("������������ ������ � �����");
            }
        }
    }
    inputFile.close();

    // �������� ������ �����
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adjacencyMatrix[i][j] != 0) {
                edges.emplace_back(i, j);
            }
        }
    }

    int m = edges.size();
    vector<vector<int>> incidenceMatrix(n, vector<int>(m, 0));

    // ��������� ������� �������������
    for (int j = 0; j < m; ++j) {
        int u = edges[j].first;
        int v = edges[j].second;
        incidenceMatrix[u][j] = 1;
        incidenceMatrix[v][j] = 1;
    }

    // ���������� ��������� � �������� ����
    ofstream outputFile("FileName2.txt");
    if (!outputFile.is_open()) {
        throw runtime_error("�� ������� ������� ���� FileName2.txt");
    }

    // ���������� ������ ������� �������������
    outputFile << n << " " << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            outputFile << incidenceMatrix[i][j] << " ";
        }
        outputFile << endl;
    }
    outputFile.close();

    return 0;
}