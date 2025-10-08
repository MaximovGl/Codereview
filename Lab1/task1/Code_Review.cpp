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
    int art_amount, required_weight;
    input >> art_amount >> required_weight;

    vector<int> weights(art_amount + 1);
    vector<int> taxes(art_amount + 1);

    for (int i = 1; i <= art_amount; ++i) {
        input >> weights[i];
    }

    for (int i = 1; i <= art_amount; ++i) {
        input >> taxes[i];
    }

    input.close();

    CalculateArts(art_amount, required_weight, weights, taxes);

    return 0;
}
