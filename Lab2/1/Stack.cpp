#include "stack.h"

using namespace std;

Stack::Stack() : top_node(nullptr), element_count(0) {}

Stack::~Stack() {
    while (top_node != nullptr) {
        Node* temp = top_node;
        top_node = top_node->next;
        delete temp;
    }
    element_count = 0;
};

void Stack::add_node(int new_node_value) {
    Node* new_node = new Node(new_node_value);
    new_node->next = top_node;
    top_node = new_node;
    ++element_count;
};

void Stack::delete_top() {
    if (top_node == nullptr) {
        cout << "Стек пуст, удалять нечего." << endl;
        return;
    }

    Node* temporary_node = top_node;
    int data_value = top_node->data;
    top_node = top_node->next;
    --element_count;

    cout << "Первый элемент стека: " << data_value << endl;
    cout << "Адрес новой вершины top_node после извлечения 1 элемента: " << top_node << endl;

    if (top_node != nullptr) {
        cout << "Значение новой вершины top_node: " << top_node->data << endl;
    }
    else {
        cout << "Стек теперь пуст." << endl;
    }

    delete temporary_node;
};

void Stack::show_stack() const {
    Node* current_node = top_node;
    if (current_node == nullptr) {
        cout << "Стек пуст." << endl;
        return;
    }
    cout << "Текущий стек (сверху вниз):" << endl;
    while (current_node != nullptr) {
        cout << current_node->data << endl;
        current_node = current_node->next;
    }
};
