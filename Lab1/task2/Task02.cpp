//Археолог нашел N артефактов.Известны веса(сi) и налоговое бремя(di) находок.
//Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил Z кг, а их об
//щее налоговое бремя оказалось минимальным.Известно, что решение единственно.Укажите
//порядковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом фай
//ле, в первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - величина
//налога по каждой находке.Вывести так же суммарный вес и общую ценность результата.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N, Z;// кол во артеф и мин треб вес
    input >> N >> Z;

    vector<int> weights(N);//вектор для хранения весов артф
    vector<int> taxes(N);//вектор для хранения налового бремени

    for (int i = 0; i < N; ++i) { //цикл для чтения весов и налогов из файла
        input >> weights[i];
    }

    for (int i = 0; i < N; ++i) {
        input >> taxes[i];
    }

    // Инициализация массива для хранения минимального налогового бремени для каждого возможного веса
    int max_possible_weight = Z + 100; // Максимально возможный вес
    vector<int> dp(max_possible_weight + 1, INT_MAX);//Создает вектор dp, где dp[j] хранит минимальное налоговое бремя для веса j. Изначально все значения равны INT_MAX
    dp[0] = 0;

    // Массив для хранения выбранных артефактов
    //Создает двумерный вектор selected, где selected[j][i] указывает, выбран ли i-й артефакт для веса j
    vector<vector<bool>> selected(max_possible_weight + 1, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) { // перебирает все артефакты
        for (int j = max_possible_weight; j >= weights[i]; --j) { //перебирает все возмож веса
            if (dp[j - weights[i]] != INT_MAX && dp[j - weights[i]] + taxes[i] < dp[j]) {
                dp[j] = dp[j - weights[i]] + taxes[i]; //обновляет мин нал бремя для веса J
                selected[j] = selected[j - weights[i]]; // Копирует выбранные артефакты для веса j - weights[i].
                selected[j][i] = true;
            }
        }
    }

    // Находим минимальное налоговое бремя для веса, превышающего Z
    int min_tax = INT_MAX;
    int best_weight = 0;
    vector<bool> best_selection;

    for (int j = Z + 1; j <= max_possible_weight; ++j) { //перебирает все веса > Z
        if (dp[j] < min_tax) {
            min_tax = dp[j];
            best_weight = j;
            best_selection = selected[j];
        }
    }

    // Выводим результат
    output << "Выбранные артефакты: ";
    for (int i = 0; i < N; ++i) {
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