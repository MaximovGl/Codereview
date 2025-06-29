/* Задача: Graf2. Построение матрицы инцидентности по матрице смежности неориентированного графа. */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Открываем входной файл
    ifstream inFile("FN1.txt");
    if (!inFile) {
        cerr << "Ошибка: не удалось открыть FileName1.txt" << endl;
        return 1;
    }

    int n;
    inFile >> n;

    // Считываем матрицу смежности
    vector<vector<int>> adjMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> adjMatrix[i][j];
        }
    }
    inFile.close();

    // Проверка симметричности матрицы смежности
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjMatrix[i][j] != adjMatrix[j][i]) {
                cerr << "Ошибка: матрица смежности не симметрична" << endl;
                return 1;
            }
        }
    }

    // Подсчёт количества рёбер (верхний треугольник)
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (adjMatrix[i][j] != 0) {
                m++;
            }
        }
    }

    // Создание и заполнение матрицы инцидентности
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

    // Запись результата в выходной файл
    ofstream outFile("FileName2.txt");
    if (!outFile) {
        cerr << "Ошибка: не удалось открыть FileName2.txt" << endl;
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
