/*Археолог нашел N артефактов.Известны веса(сi) и налоговое бремя(di) находок.
Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил Z кг, а их общее
налоговое бремя оказалось минимальным.Известно, что решение единственно.Укажите
порядковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле,
в первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - величина
налога по каждой находке.Вывести так же суммарный вес и общую ценность результата.
*/
#ifndef SELECT_ARTS_H
#define SELECT_ARTS_H

#include <vector> 
#include <iostream>

void SelectArts(std::vector<std::vector<int>>& min_tax_for_weights, int curr_art, int curr_weight, std::vector<int>& weights, std::vector<int>& taxes);
void CalculateArts(int art_amount, int required_weight, std::vector<int>& weights, std::vector<int>& taxes);

#endif
