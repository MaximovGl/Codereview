/* ���������� ������� ������������� ������������������ ����� �� ������� ��������� */
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

int main() {
    try {
        // �������� �������� �����
        ifstream fin("FN1.txt");
        if (!fin.is_open()) {
            throw runtime_error("Cannot open input file");
        }

        // ������ ���������� ������
        int n;
        fin >> n;
        if (n <= 0) {
            throw runtime_error("Invalid vertex count");
        }

        // ������ ������� ���������
        vector<vector<int>> adj(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                fin >> adj[i][j];
            }
        }
        fin.close();

        // ������� ���������� ���� � ���������� ������� �������������
        vector<vector<int>> inc(n);
        int m = 0;

        // ������ �� ���� �������� (i) � �� ������� (j)
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (adj[i][j] != 0) {
                    // ���������� ������ �����
                    for (int k = 0; k < n; ++k) {
                        // ������������� ������� ������
                        if (k == i) {
                            inc[k].push_back(1); // ������� i ����������
                        }
                        else if (k == j && i != j) {
                            inc[k].push_back(1); // ������� j ���������� (����� ������)
                        }
                        else {
                            inc[k].push_back(0);
                        }
                    }
                    ++m;
                }
            }
        }

        // ������ ���������� � �������� ����
        ofstream fout("FileName2");
        if (!fout.is_open()) {
            throw runtime_error("Cannot open output file");
        }

        fout << n << " " << m << "\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                fout << inc[i][j] << " ";
            }
            fout << "\n";
        }
        fout.close();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}