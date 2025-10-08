#include "SelectArts.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

void SelectArts(vector<vector<int>>& weight_tax, int curr_art, int curr_weight, vector<int>& weights, vector<int>& taxes) {
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

    vector<vector<int>> weight_tax(art_amount + 1, vector<int>(max_weight + 1, 2147483647));
    for (int i = 0; i <= art_amount; ++i) {
        weight_tax[i][0] = 0;
    }

    for (int curr_art = 1; curr_art <= art_amount; curr_art++) {
        for (int curr_weight = 1; curr_weight <= max_weight; curr_weight++) {
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
