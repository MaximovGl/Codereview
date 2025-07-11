/*CalcTree9. � ��������� ����� � ������ FN1 ���� �������������� ��������� � ���������
�����. � ��������� ����� �������������� ��������: ��������(+), ���������(-), ���������(*),
������� ������(/), ������� �� �������(%), ���������� � �������(^), � ��� �� ����� ����� �� ���
������� [1; 30] � ���������� x. ��� �������� ���������� � ������� ���������� ������� ������
��������� ����� �����. ��������� ������ ���������. ����� ����� ��������� �������� ������
��� ��� �������� �������� ���������� x � �������� ��������� � ��������� ���� � ������ FN2.
������������ ������, ������� ��� ���������� ���� A+x �� x+A, ��� A - ��������� ���������, � x - ����������. ������������ ������ ����� �������������� � ���� FN2 � ���������� � ��������
��� �����, � ��� �� � ��������� ����� � ����������� ��������. ��� ������� ���������� ���
��� ������ ���������� �������� ������ ������ ��������� �� �������: �������� �����������
���������� ����������� �� ������� ����� �������. ����� �������, ��������� 2+3+4+5, �����
���, ������ ������������ ��� ((2+3)+4)+5, � �� ����� ������������ ��� (2+3)+(4+5) ���
2+(3+(4+5)). ���������� ���� ����������, ������� �������������, ����������� ���� int. */

/**
 * @file expression_tree.h
 * @brief ������������ ���� ��� ������ � ��������� ���������
 */

#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <string>
#include <vector>
#include <fstream>

 /**
  * @brief ���� ��������� ������ ���������
  */
struct Node {
    std::string token;   
    Node* left;          
    Node* right;         
};

/**
 * @brief ��������� ������ ��������� �� ������
 * @param expr ������� ���������
 * @return ������ �������
 */
std::vector<std::string> tokenize(const std::string& expr);

/**
 * @brief ����������� ��������� ������� � �����������
 * @param tokens ������ ������� � ��������� �����
 * @return ������ ������� � ����������� �����
 */
std::vector<std::string> infixToPostfix(const std::vector<std::string>& tokens);

/**
 * @brief ������ ������ ��������� �� ����������� �������
 * @param postfix ������ ������� � ����������� �����
 * @return ��������� �� ������ ������
 */
Node* buildTree(const std::vector<std::string>& postfix);

/**
 * @brief ��������� �������� ���������
 * @param root ������ ������ ���������
 * @param x_value �������� ���������� x
 * @return ��������� ����������
 */
int evaluate(Node* root, int x_value);

/**
 * @brief ����������� ������ �� ������� A+x -> x+A
 * @param root ������ ������ ���������
 */
void transformTree(Node* root);

/**
 * @brief �������� ������ � ���������� �����
 * @param root ������ ������
 * @param fout �������� �������� �����
 */
void printPrefix(Node* root, std::ofstream& fout);

/**
 * @brief �������� ������ � ����������� �����
 * @param root ������ ������
 * @param fout �������� �������� �����
 */
void printPostfix(Node* root, std::ofstream& fout);

/**
 * @brief �������� ������ � ��������� ����� � ����������� ��������
 * @param root ������ ������
 * @param fout �������� �������� �����
 */
void printInfix(Node* root, std::ofstream& fout);

/**
 * @brief ������� ������ ���������
 * @param root ������ ������
 */
void deleteTree(Node* root);

/**
 * @brief ������������ ���������: ���������, ����������� � ������� ����������
 * @param expression ������� ���������
 * @param x_value �������� ���������� x
 * @param outputFile ��� ��������� �����
 * @return ��� ���������� (0 - �����, 1 - ������)
 */
int processExpression(const std::string& expression, int x_value,
    const std::string& outputFile);

#endif