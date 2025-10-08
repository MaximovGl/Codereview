#include "SelectArts.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

void SelectArts(vector<vector<int>>& weight_tax, int curr_art, int curr_weight, vector<int>& weights, vector<int>& taxes) {
    /*FIXME скобки
    if (curr_art == 0 || curr_weight == 0)
        return;
    */
    if (curr_art == 0 || curr_weight == 0) {
        return;
    }
    if (weight_tax[curr_art][curr_weight] == weight_tax[curr_art - 1][curr_weight]) {
        SelectArts(weight_tax, curr_art - 1, curr_weight, weights, taxes);
    }
    else {
        cout << curr_art << ' ';
        SelectArts(weight_tax, curr_art - 1, curr_weight - weights[curr_art], weights, taxes);
    }
}

void CalculateArts(int art_amount, int required_weight, vector<int>& weights, vector<int>& taxes) {
    int max_weight = 0;
    for (int w : weights) {
        max_weight += w;
    }


    /* FIXME название переменных + максимальное значение int
    vector<vector<int>> dp(art_amount + 1, vector<int>(max_weight + 1, 999));
    for (int i = 0; i <= art_amount; i++) {
        dp[i][0] = 0;
    }
    */

    vector<vector<int>> weight_tax(art_amount + 1, vector<int>(max_weight + 1, 2147483647));
    for (int i = 0; i <= art_amount; ++i) {
        weight_tax[i][0] = 0;
    }
    /*FIXME непонятная переменная
    for (int s = 1; s <= max_weight; s++) {
    */
    for (int curr_art = 1; curr_art <= art_amount; curr_art++) {  //проходим по всем  артефактам
        for (int curr_weight = 1; curr_weight <= max_weight; curr_weight++) { //Проходим по всем весам от 1 до max.
            if (curr_weight >= weights[curr_art] && weight_tax[curr_art - 1][curr_weight - weights[curr_art]] != 2147483647) { 
                weight_tax[curr_art][curr_weight] = min(weight_tax[curr_art - 1][curr_weight], weight_tax[curr_art - 1][curr_weight - weights[curr_art]] + taxes[curr_art]);
            }
            else {
                weight_tax[curr_art][curr_weight] = weight_tax[curr_art - 1][curr_weight];
            }
        }
    }

    int min_tax = INT_MAX;
    int total_weight = 0;
    
    for (int curr_weight = required_weight + 1; curr_weight <= max_weight; curr_weight++) {
        if (weight_tax[art_amount][curr_weight] < min_tax) {
            min_tax = weight_tax[art_amount][curr_weight];
            total_weight = curr_weight;
        }
    }

    cout << "Выбранные артефакты -> ";
    SelectArts(weight_tax, art_amount, total_weight, weights, taxes);
    cout << endl;

    cout << "Суммарный вес -> " << total_weight << " кг" << endl;
    cout << "Общее налоговое бремя -> " << min_tax << endl;
}
