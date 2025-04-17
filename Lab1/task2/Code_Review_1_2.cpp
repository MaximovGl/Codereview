//FIXME задача не по шаблону
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
//#include <algorithm>
//#include <climits>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    //FIXME однобуквенные переменные 

    /*int N, Z;
    input >> N >> Z;
    */

    int art_amount, min_weight;// кол во артеф и мин треб вес
    input >> art_amount >> min_weight;

    vector<int> weights(art_amount);//вектор для хранения весов артф
    vector<int> taxes(art_amount);//вектор для хранения налового бремени

    for (int i = 0; i < art_amount; ++i) { //цикл для чтения весов и налогов из файла
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

    // Инициализация массива для хранения минимального налогового бремени для каждого возможного веса
    int max_possible_weight = min_weight + 100; // Максимально возможный вес
    vector<int> min_tax_for_weights(max_possible_weight + 1, INT_MAX);//Создает вектор min_tax_for_weights, где min_tax_for_weights[j] хранит минимальное налоговое бремя для веса j. Изначально все значения равны INT_MAX
    min_tax_for_weights[0] = 0;

    // Массив для хранения выбранных артефактов
    //Создает двумерный вектор selected, где selected[j][i] указывает, выбран ли i-й артефакт для веса j
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

    // Находим минимальное налоговое бремя для веса, превышающего min_weight
    int min_tax = INT_MAX;
    int best_weight = 0;
    vector<bool> best_selection;

    for (int j = min_weight + 1; j <= max_possible_weight; ++j) { //перебирает все веса > min_weight
        if (min_tax_for_weights[j] < min_tax) {
            min_tax = min_tax_for_weights[j];
            best_weight = j;
            best_selection = selected[j];
        }
    }

    // Выводим результат
    output << "Выбранные артефакты: ";
    for (int i = 0; i < art_amount; ++i) {
        if (best_selection[i]) {
            output << i + 1 << " ";
        }
    }
    output << endl;

    output << "Суммарный вес: " << best_weight << " кг" << endl;
    output << "Общее налоговое бремя: " << min_tax << endl;

    input.close();
    output.close();

    return 0;
}