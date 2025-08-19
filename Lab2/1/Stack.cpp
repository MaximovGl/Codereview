#include "stack.h"

using namespace std;

Stack::Stack() : p1(nullptr), counter(0) {}

Stack::~Stack() {
  while (p1 != nullptr) {
    Node* temp = p1;
    p1 = p1->next;
    delete temp;
  }
  counter = 0;
}

void Stack::AddNode(int new_node_value) {
  Node* new_node = new Node(new_node_value);
  new_node->next = p1;
  p1 = new_node;
  ++counter;
}

void Stack::DeleteTop() {
  if (p1 == nullptr) {
    cout << "Стек пуст, удалять нечего." << endl;
    return;
  }

  Node* temporary_node = p1;
  int d = p1->data;
  p1 = p1->next;
  --counter;

  cout << "Первый элемент стека: " << d << endl;
  cout << "Адрес новой вершины p1 после извлечения 1 элемента: " << p1 << endl;

  if (p1 != nullptr) {
    cout << "Значение новой вершины p1: " << p1->data << endl;
  } else {
    cout << "Стек теперь пуст." << endl;
  }

  delete temporary_node;
}

void Stack::ShowStack() const {
  Node* temporary_node = p1;
  if (temporary_node == nullptr) {
    cout << "Стек пуст." << endl;
    return;
  }
  cout << "Текущий стек (сверху вниз):" << endl;
  while (temporary_node != nullptr) {
    cout << temporary_node->data << endl;
    temporary_node = temporary_node->next;
  }
}
