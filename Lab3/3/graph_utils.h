/**
 * @file graph_utils.h
 * @brief ������������ ���� ��� ������ � �������
 */

#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include <vector>
#include <string>

 /**
  * @brief ������������ ����: ������ ������� ���������, ������ ������� �������������
  * @param inputFile ��� �������� ����� � �������� ���������
  * @param outputFile ��� ��������� ����� ��� ������� �������������
  * @return true ���� ��������� �������, false ��� ������
  */
bool processGraph(const std::string& inputFile, const std::string& outputFile);

/**
 * @brief ������ ������� ��������� �� �����
 * @param filename ��� ����� ��� ������
 * @param n[out] ���������� ������ �����
 * @param adjMatrix[out] ������� ���������
 * @return true ���� ������ �������, false ��� ������
 */
bool readAdjacencyMatrix(const std::string& filename, int& n,
    std::vector<std::vector<int>>& adjMatrix);

/**
 * @brief ��������� �������������� �������
 * @param matrix ����������� �������
 * @return true ���� ������� �����������, ����� false
 */
bool isSymmetric(const std::vector<std::vector<int>>& matrix);

/**
 * @brief ������������ ���������� ���� � �����
 * @param adjMatrix ������� ���������
 * @return ���������� ���� � �����
 */
int countEdges(const std::vector<std::vector<int>>& adjMatrix);

/**
 * @brief ������ ������� �������������
 * @param adjMatrix ������� ���������
 * @param n ���������� ������
 * @param m ���������� ����
 * @return ������� ������������� �������� n x m
 */
std::vector<std::vector<int>> buildIncidenceMatrix(
    const std::vector<std::vector<int>>& adjMatrix, int n, int m);

/**
 * @brief ���������� ������� ������������� � ����
 * @param filename ��� ��������� �����
 * @param incMatrix ������� �������������
 * @param n ���������� ������
 * @param m ���������� ����
 * @return true ���� ������ �������, false ��� ������
 */
bool writeIncidenceMatrix(const std::string& filename,
    const std::vector<std::vector<int>>& incMatrix,
    int n, int m);

#endif