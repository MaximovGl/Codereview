/**
 * @file graph_utils.cpp
 * @brief Реализация функций для работы с графами
 */

#include "graph_utils.h"
#include <fstream>
#include <iostream>

using namespace std;

bool processGraph(const string& inputFile, const string& outputFile) {
    int n;
    vector<vector<int>> adjMatrix;

    if (!readAdjacencyMatrix(inputFile, n, adjMatrix)) {
        cerr << "Ошибка при чтении входного файла: " << inputFile << endl;
        return false;
    }

    if (!isSymmetric(adjMatrix)) {
        cerr << "Ошибка: матрица смежности не симметрична" << endl;
        return false;
    }

    int m = countEdges(adjMatrix);
    vector<vector<int>> incMatrix = buildIncidenceMatrix(adjMatrix, n, m);

    if (!writeIncidenceMatrix(outputFile, incMatrix, n, m)) {
        cerr << "Ошибка при записи выходного файла: " << outputFile << endl;
        return false;
    }

    return true;
}

bool readAdjacencyMatrix(const string& filename, int& n,
    vector<vector<int>>& adjMatrix)
{
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Ошибка: не удалось открыть " << filename << endl;
        return false;
    }

    if (!(inFile >> n)) {
        cerr << "Ошибка: не удалось считать количество вершин" << endl;
        return false;
    }

    if (n <= 0) {
        cerr << "Ошибка: некорректное количество вершин: " << n << endl;
        return false;
    }

    adjMatrix.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(inFile >> adjMatrix[i][j])) {
                cerr << "Ошибка чтения элемента матрицы ["
                    << i << "][" << j << "]" << endl;
                return false;
            }
        }
    }
    inFile.close();
    return true;
}

bool isSymmetric(const vector<vector<int>>& matrix) {
    size_t n = matrix.size();
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int countEdges(const vector<vector<int>>& adjMatrix) {
    int count = 0;
    size_t n = adjMatrix.size();
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i; j < n; j++) {
            if (adjMatrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

vector<vector<int>> buildIncidenceMatrix(
    const vector<vector<int>>& adjMatrix, int n, int m)
{
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
    return incMatrix;
}

bool writeIncidenceMatrix(const string& filename,
    const vector<vector<int>>& incMatrix,
    int n, int m)
{
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Ошибка: не удалось создать " << filename << endl;
        return false;
    }

    outFile << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            outFile << incMatrix[i][j];
            if (j < m - 1) outFile << " ";
        }
        outFile << endl;
    }

    if (!outFile.good()) {
        cerr << "Ошибка записи в файл " << filename << endl;
        return false;
    }

    outFile.close();
    return true;
}