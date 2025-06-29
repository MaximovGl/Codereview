/**
 * @file graph_utils.h
 * @brief Заголовочный файл для работы с графами
 */

#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include <vector>
#include <string>

 /**
  * @brief Обрабатывает граф: читает матрицу смежности, строит матрицу инцидентности
  * @param inputFile Имя входного файла с матрицей смежности
  * @param outputFile Имя выходного файла для матрицы инцидентности
  * @return true если обработка успешна, false при ошибке
  */
bool processGraph(const std::string& inputFile, const std::string& outputFile);

/**
 * @brief Читает матрицу смежности из файла
 * @param filename Имя файла для чтения
 * @param n[out] Количество вершин графа
 * @param adjMatrix[out] Матрица смежности
 * @return true если чтение успешно, false при ошибке
 */
bool readAdjacencyMatrix(const std::string& filename, int& n,
    std::vector<std::vector<int>>& adjMatrix);

/**
 * @brief Проверяет симметричность матрицы
 * @param matrix Проверяемая матрица
 * @return true если матрица симметрична, иначе false
 */
bool isSymmetric(const std::vector<std::vector<int>>& matrix);

/**
 * @brief Подсчитывает количество рёбер в графе
 * @param adjMatrix Матрица смежности
 * @return Количество рёбер в графе
 */
int countEdges(const std::vector<std::vector<int>>& adjMatrix);

/**
 * @brief Строит матрицу инцидентности
 * @param adjMatrix Матрица смежности
 * @param n Количество вершин
 * @param m Количество рёбер
 * @return Матрица инцидентности размером n x m
 */
std::vector<std::vector<int>> buildIncidenceMatrix(
    const std::vector<std::vector<int>>& adjMatrix, int n, int m);

/**
 * @brief Записывает матрицу инцидентности в файл
 * @param filename Имя выходного файла
 * @param incMatrix Матрица инцидентности
 * @param n Количество вершин
 * @param m Количество рёбер
 * @return true если запись успешна, false при ошибке
 */
bool writeIncidenceMatrix(const std::string& filename,
    const std::vector<std::vector<int>>& incMatrix,
    int n, int m);

#endif