#include "list.h"
#include <iostream>
#include <limits>

SortedList::SortedList() : head(nullptr), tail(nullptr), size(0) {}

SortedList::~SortedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
}

void SortedList::append(int value) {
    Node* new_node = new Node(value);
    if (tail == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

void SortedList::insert_sorted(int value) {
    Node* new_node = new Node(value);
    
    if (head == nullptr || head->data >= value) {
        new_node->next = head;
        head = new_node;
        if (tail == nullptr) {
            tail = new_node;
        }
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        if (new_node->next == nullptr) {
            tail = new_node;
        }
    }
    size++;
}

void SortedList::remove(int value) {
    if (head == nullptr) return;
    
    if (head->data == value) {
        Node* node_to_delete = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete node_to_delete;
        size--;
        return;
    }
    
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next != nullptr) {
        Node* node_to_delete = current->next;
        current->next = node_to_delete->next;
        if (node_to_delete == tail) {
            tail = current;
        }
        delete node_to_delete;
        size--;
    }
}

bool SortedList::contains(int value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SortedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

SortedList SortedList::create_copy() const {
    SortedList copy;
    Node* current = head;
    while (current != nullptr) {
        copy.append(current->data);
        current = current->next;
    }
    return copy;
}

int read_integer() {
    int value = 0;
    while (!(std::cin >> value)) {
        std::cerr << "Ошибка ввода! Пожалуйста, введите целое число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

void run_task() {
    SortedList original_list;
    int element_count = 0;
    int value_to_insert = 0;
    
    std::cout << "Добро пожаловать!" << std::endl;
    std::cout << "Перед нами последняя задача: " << std::endl;
    std::cout << "Дан односвязный линейный список. Значения элементов списка упорядочены по возрастанию." << std::endl;
    std::cout << "Необходимо создать копию исходного списка, после чего в вновь созданный список вставить" << std::endl;
    std::cout << "значение M так, чтобы он остался упорядоченным и вывести ссылку на первый элемент полученного списка P2." << std::endl << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Вам необходимо будет ввести количество элементов в списке," << std::endl;
    std::cout << "а позже ввести значения элементов СТРОГО В ПОРЯДКЕ ВОЗРАСТАНИЯ " << std::endl;
    std::cout << "и ввести число которое вы хотите вставить." << std::endl;
    std::cout << "ПРИМЕР ПОРЯДКА ВОЗРАСТАНИЯ 1 2 3 4 5 6" << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Введите число n - количество элементов в списке: ";
    element_count = read_integer();
    
    std::cout << std::endl << "Введите " << element_count << " чисел в порядке возрастания (!!!!): ";
    for (int i = 0; i < element_count; ++i) {
        int value = read_integer();
        original_list.append(value);
    }

    std::cout << std::endl << "Введите целое значение числа m, которое необходимо будет вставить: ";
    value_to_insert = read_integer();
    
    std::cout << "Исходный список: ";
    original_list.display();
    std::cout << std::endl;
    
    SortedList copied_list = original_list.create_copy();
    copied_list.insert_sorted(value_to_insert);
    
    std::cout << "Список после вставки: ";
    copied_list.display();
    
    int choice;
    std::cout << std::endl << "Хотите удалить какой-нибудь элемент?" << std::endl;
    std::cout << "Если да, то напишите 1" << std::endl;
    std::cout << "Если нет, то напишите 2" << std::endl;
    std::cout << "Ваш выбор: ";
    choice = read_integer();
    std::cout << std::endl;
    
    switch (choice) {
    case 1: {
        std::cout << "Введите число - количество элементов которое вы хотите удалить: ";
        int delete_count = read_integer();
        for (int i = 0; i < delete_count; ++i) {
            std::cout << "Введите значение элемента, который вы хотите удалить: ";
            int value_to_delete = read_integer();
            copied_list.remove(value_to_delete);
        }
        std::cout << "Список после удаления: ";
        copied_list.display();
    } break;

    case 2: {
        std::cout << "Спасибо за терпение!!!" << std::endl;
        std::cout << "До свидания!!!" << std::endl;
    } break;

    default: {
        std::cerr << "Введено неверное число";
        break;
    }
    }
}
