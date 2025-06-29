/* Построение матрицы инцидентности неориентированного графа из матрицы смежности */
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

int main() {
    try {
        // Открытие входного файла
        ifstream fin("FN1.txt");
        if (!fin.is_open()) {
            throw runtime_error("Cannot open input file");
        }

        // Чтение количества вершин
        int n;
        fin >> n;
        if (n <= 0) {
            throw runtime_error("Invalid vertex count");
        }

        // Чтение матрицы смежности
        vector<vector<int>> adj(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                fin >> adj[i][j];
            }
        }
        fin.close();

        // Подсчёт количества рёбер и построение матрицы инцидентности
        vector<vector<int>> inc(n);
        int m = 0;

        // Проход по всем вершинам (i) и их соседям (j)
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (adj[i][j] != 0) {
                    // Добавление нового ребра
                    for (int k = 0; k < n; ++k) {
                        // Инициализация столбца нулями
                        if (k == i) {
                            inc[k].push_back(1); // Вершина i инцидентна
                        }
                        else if (k == j && i != j) {
                            inc[k].push_back(1); // Вершина j инцидентна (кроме петель)
                        }
                        else {
                            inc[k].push_back(0);
                        }
                    }
                    ++m;
                }
            }
        }

        // Запись результата в выходной файл
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