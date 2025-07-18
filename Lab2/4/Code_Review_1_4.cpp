﻿/* Дан двусвязный линейный список и указатель на первый элемент этого
списка. Создать текстовый файл, в который вывести содержимое списка в обратном
порядке. По ходу вывода списка удалять элементы в нем. Числа выводить в одну строку,
разделяя ровно одним пробелом, в конце строки пробел на ставить.


Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен стандартный
набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно наличие
дружественного интерфейса. Ввод данных с клавиатуры. */


#include "linked_list.h"

int main() {
    setlocale(LC_ALL, "Russian");
    processLinkedListWork();
    return 0;
}