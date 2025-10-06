#include "linked_list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::append(int value) {
    Node* new_node = new Node(value);
    
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

bool DoublyLinkedList::remove_value(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

void DoublyLinkedList::display() const {
    Node* current = head;
    std::cout << "Список: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::write_to_file_and_clear(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    Node* current = tail;
    bool first_element = true;
    while (current != nullptr) {
        if (first_element) {
            file << current->data;
            first_element = false;
        } else {
            file << " " << current->data;
        }
        current = current->prev;
    }

    file.close();
    clear();
    std::cout << "Данные записаны в файл и список очищен." << std::endl;
}

void DoublyLinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
    head = nullptr;
    tail = nullptr;
}

int read_integer_input() {
    std::string input;
    while (true) {
        std::cout << "Введите число (или '-1' для завершения): ";
        std::cin >> input;

        if (input == "-1") {
            return -1;
        }

        bool is_valid = true;
        int sign = 1;
        size_t start_index = 0;

        if (input.empty()) {
            is_valid = false;
        } else if (input[0] == '-') {
            sign = -1;
            start_index = 1;
            if (input.size() == 1) is_valid = false;
        }

        for (size_t i = start_index; i < input.size(); ++i) {
            if (!isdigit(input[i])) {
                is_valid = false;
                break;
            }
        }

        if (is_valid) {
            int number = 0;
            for (size_t i = start_index; i < input.size(); ++i) {
                number = number * 10 + (input[i] - '0');
            }
            return number * sign;
        } else {
            std::cerr << "Некорректный ввод! Используйте цифры и знак '-' в начале." << std::endl;
        }
    }
}

void display_file_contents(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return;
    }

    std::cout << "\n=== Содержимое файла ===" << std::endl;
    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void execute_linked_list_workflow() {
    DoublyLinkedList list;

    std::cout << "=== Ввод чисел в список ===" << std::endl;
    while (true) {
        int number = read_integer_input();
        if (number == -1) break;
        list.append(number);
    }

    list.display();

    std::cout << "\n=== Запись в файл ===" << std::endl;
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    list.write_to_file_and_clear(filename);
    display_file_contents(filename);
}
