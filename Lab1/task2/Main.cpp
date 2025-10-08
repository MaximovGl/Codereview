#include "Code_Review_1_2.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        cout << "Ошибка при открытии файлов" << endl;
        return 1;
    }

    CalculateArts(input, output);

    input.close();
    output.close();

    return 0;
}
