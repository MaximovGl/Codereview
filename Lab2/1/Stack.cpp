#include "Stack.h"
#include <iostream>
#include <cstdlib>
#include <limits> 

using namespace std;

Node::Node(int d) :x(d), next(nullptr) {}

Stack::Stack() : top(nullptr) {}

void Stack::Push(int d) {
    Node* newNode = new Node(d);
    newNode->next = top;
    top = newNode;
}

void Stack::Show() const {
    Node* current = top;
    while (current != nullptr) {
        cout << current->x << " ";
        current = current->next;
    }
    cout << endl;
}

void Stack::ShowAddress() const {
    cout << "����� ������� �����: " << top << endl;
}

int Stack::GetTopValue() const {
    if (top != nullptr) {
        return top->x;
    }
    cerr << "������: ������� �������� �������� �� ������� �����!" << endl;
    exit(EXIT_FAILURE);
}

bool Stack::IsEmpty() const {
    return top == nullptr;
}

int Read_int() {
    int m = 0;
    while (!(cin >> m)) {
        cerr << "������ �����! ����������, ������� ����� �����: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return m;
}

void RunStackOperations(Stack& stack) {
    int N = 0;
    int n = 0;

    cout << "������� ����� �� ������, ����� ���� � �����? ";
    N = Read_int();

    for (int i = 0; i < N; ++i) {
        cout << "������� ����� " << i + 1 << ": ";
        while (!(cin >> n)) {
            cerr << "������ �����! ����������, ������� ����� �����: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        stack.Push(n);
    }

    stack.ShowAddress();

    cout << "�������� � �����: ";
    stack.Show();

    int D = 0;

    cout << "������� �������� D ��� ���������� � ����: ";
    D = Read_int();
    stack.Push(D);

    cout << "�������� � ����� �����: ";
    stack.Show();
    stack.ShowAddress();

    if (!stack.IsEmpty()) {
        cout << "�������� ����� �������: " << stack.GetTopValue() << endl;
    }
    else {
        cout << "���� ����!" << endl;
    }
}