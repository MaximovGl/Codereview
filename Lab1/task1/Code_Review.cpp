//FIXME задача не по шаблону
//Археолог нашел N артефактов.Известны веса(сi) и налоговое бремя(di) находок.
//Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил Z кг, а их об
//щее налоговое бремя оказалось минимальным.Известно, что решение единственно.Укажите
//порядковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом фай
//ле, в первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - величина
//налога по каждой находке.Вывести так же суммарный вес и общую ценность результата.


#include "SelectArts.h"
#include <iostream>
#include <fstream>
//FIXME запрещено использование windows.h
//#include <Windows.h>

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

int main() {
    //FIXME запрещено использование windows.h
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    ifstream input("1.1.txt");
    if (!input.is_open()) {
        cout << "Ошибка при открытии файла" << endl;
        return 1;
    }
    /*FIXME Непонятные названия переменных
    int N, Z;
    */
    int art_amount, required_weight;
    input >> art_amount >> required_weight;

    vector<int> weights(art_amount + 1);
    //FIXME название переменной не соответствует сожержанию.
    //vector<int> time(art_amount + 1);
    vector<int> taxes(art_amount + 1);

    for (int i = 1; i <= art_amount; ++i) {
        input >> weights[i];
    }

    for (int i = 1; i <= art_amount; ++i) {
        input >> taxes[i];
    }

    input.close();

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

    return 0;
}
