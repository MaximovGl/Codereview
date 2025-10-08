﻿//FIXME задача не по шаблону
//Археолог нашел art_amount артефактов.Известны веса(сi) и налоговое бремя(di) находок.
//Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил min_weight кг, а их об
//щее налоговое бремя оказалось минимальным.Известно, что решение единственно.Укажите
//порядковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом фай
//ле, в первой строке указаны art_amount и min_weight, а во второй строке значения весов(в кг), в третьей - величина
//налога по каждой находке.Вывести так же суммарный вес и общую ценность результата.

#include "Code_Review_1_2.h"
#include <iostream>
#include <fstream>
#include <vector>
//FIXME библиотеки не используются
//#include <algorithm>
//#include <climits>

using namespace std;

void CalculateArts(ifstream& input, ofstream& output) {
    //FIXME однобуквенные переменные 

    /*int N, Z;
    input >> N >> Z;
    */

    int art_amount, min_weight;
    input >> art_amount >> min_weight;

    vector<int> weights(art_amount);
    vector<int> taxes(art_amount);

    for (int i = 0; i < art_amount; ++i) { 
        input >> weights[i];
    }

    for (int i = 0; i < art_amount; ++i) {
        input >> taxes[i];
    }

    /*FIXME непонатное название переменной
    int max_possible_weight = min_weight + 100; 
    vector<int> dp(max_possible_weight + 1, INT_MAX);
    dp[0] = 0;
    */

    int total_max_weight = 0;
    for (int w : weights) {
        total_max_weight += w;
    }
    int max_possible_weight = total_max_weight;
    vector<int> min_tax_for_weights(max_possible_weight + 1, INT_MAX);
    min_tax_for_weights[0] = 0;

    vector<vector<bool>> selected(max_possible_weight + 1, vector<bool>(art_amount, false));

    for (int i = 0; i < art_amount; ++i) { // перебирает все артефакты
        for (int j = max_possible_weight; j >= weights[i]; --j) { //перебирает все возмож веса
            if (min_tax_for_weights[j - weights[i]] != INT_MAX && min_tax_for_weights[j - weights[i]] + taxes[i] < min_tax_for_weights[j]) {
                min_tax_for_weights[j] = min_tax_for_weights[j - weights[i]] + taxes[i]; //обновляет мин нал бремя для веса J
                selected[j] = selected[j - weights[i]]; // Копирует выбранные артефакты для веса j - weights[i].
                selected[j][i] = true;
            }
        }
    }

    int min_tax = INT_MAX;
    int best_weight = 0;
    vector<bool> best_selection;

    for (int j = min_weight + 1; j <= max_possible_weight; ++j) {
        if (min_tax_for_weights[j] < min_tax) {
            min_tax = min_tax_for_weights[j];
            best_weight = j;
            best_selection = selected[j];
        }
    }

    output << "Выбранные артефакты: ";
    for (int i = 0; i < art_amount; ++i) {
        if (best_selection[i]) {
            output << i + 1 << " ";
        }
    }
    output << endl;

    output << "Суммарный вес: " << best_weight << " кг" << endl;
    output << "Общее налоговое бремя: " << min_tax << endl;
}

