/*�������� ����� N ����������.�������� ����(�i) � ��������� �����(di) �������.
����� ������� ����� ������������ �������, ����� �� ��������� ��� �������� Z ��, � �� �����
��������� ����� ��������� �����������.��������, ��� ������� �����������.�������
���������� ������ �����, ������� ����� �����.�������� ������ ��������� � ��������� �����,
� ������ ������ ������� N � Z, � �� ������ ������ �������� �����(� ��), � ������� - ��������
������ �� ������ �������.������� ��� �� ��������� ��� � ����� �������� ����������.
*/
#ifndef SELECT_ARTS_H
#define SELECT_ARTS_H

#include <vector> 

void SelectArts(std::vector<std::vector<int>>& min_tax_for_weights, int curr_art, int curr_weight, std::vector<int>& weights, std::vector<int>& taxes);

#endif