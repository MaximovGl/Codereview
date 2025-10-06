/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)

Даны списки L1 и L2; список L1 имеет нечетное количество элементов.
Переместить средний элемент списка L1 в конец списка L2. Использовать один вызов
функции-члена splice.

*/


#include "containers.h"
#include <iostream>
#include <locale>

int main() {
    setlocale(LC_ALL, "Russian");
    int first_list_size, second_list_size;
    std::list<int> first_list;
    std::list<int> second_list;

    std::cout << "Введите размер списка L1 (нечетное число): ";
    std::cin >> first_list_size;
    std::cout << "Введите размер списка L2: ";
    std::cin >> second_list_size;

    if (first_list_size <= 0 || second_list_size < 0) {
        std::cerr << "Ошибка: некорректный размер списка" << std::endl;
        return 1;
    }
    if (first_list_size % 2 == 0) {
        std::cerr << "Ошибка: размер L1 должен быть нечетным" << std::endl;
        return 1;
    }

    if (!fill_list(first_list, first_list_size)) {
        std::cerr << "Ошибка заполнения L1" << std::endl;
        return 1;
    }
    if (!fill_list(second_list, second_list_size)) {
        std::cerr << "Ошибка заполнения L2" << std::endl;
        return 1;
    }

    std::cout << "\nИсходные списки:" << std::endl;
    std::cout << "L1 (прямой порядок): ";
    print_list(first_list);
    std::cout << "L1 (обратный порядок): ";
    print_list_reverse(first_list);
    std::cout << "L2: ";
    print_list(second_list);

    move_middle_element(first_list, second_list);

    std::cout << "\nРезультат обработки:" << std::endl;
    std::cout << "L1: ";
    print_list(first_list);
    std::cout << "L2: ";
    print_list(second_list);

    return 0;
}
