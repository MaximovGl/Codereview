#include "queue.h"
#include <iostream>
#include <limits>

using namespace std;

void Add(int data, PNode& Head, PNode& Tail) {
    PNode Temp;
    if (Head == nullptr) {
        Head = new Node;
        Tail = Head;
        Head->next = nullptr;
    }
    else {
        Temp = new Node;
        Tail->next = Temp;
        Tail = Temp;
        Tail->next = nullptr;
    }
    Tail->data = data;
}

int Show_Before(PNode head) {
    if (head == nullptr) {
        cerr << "������: ������� �������� ������ �������!" << endl;
        return 1;
    }

    PNode temp = head;
    cout << endl << "�������� ����� ������� ��������: " << head << " " << head->data;

    cout << endl << "�������� �������: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    PNode last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    cout << endl << "�������� ����� ���������� ��������: " << last << " " << last->data << endl;
    return 0;
}

int Delete(int m, PNode& Head) {
    if (m < 0) {
        cerr << "������: ���������� ��������� ��������� �� ����� ���� �������������!" << endl;
        return 1;
    }
    if (Head == nullptr) {
        return 0;
    }

    PNode temp;
    for (int i = 0; i < m && Head != nullptr; ++i) {
        temp = Head;
        Head = Head->next;
        delete temp;
    }
    return 0;
}

void Show_After(PNode head) {
    if (head == nullptr) {
        cout << "������� ����� �������� ��������� ��������� ������" << endl;
        cout << "������ �������: nullptr" << endl;
        cout << "����� �������: nullptr" << endl;
    }
    else {
        PNode temp2 = head;
        cout << "����� ������ �������: " << temp2 << " " << temp2->data << endl;
        cout << "���������� �������� �������: ";
        PNode current = head;
        PNode last = nullptr;
        while (current != nullptr) {
            last = current;
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl << "����� ����� �������: " << last << " " << last->data << endl;
    }
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

int RunQueueOperations() {
    int m = 0;
    int n = 0;
    PNode p1 = nullptr;
    PNode p2 = nullptr;

    cout << "����� ����������!" << endl;
    cout << "����� ���� ����� ������:" << endl;
    cout << "���� ����� N (> 0) � ��������� P1 � P2 �� ������ � ����� �������� �������." << endl;
    cout << "������� �� ������� N ��������� ���������" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "��� ���������� ������ ���������� ��������� ������� � �� �������� ����� ������ " << endl;
    cout << "�� ������� ����� ������ ������ � ����� �������, �������� n �������� � ������� �� �����" << endl;
    cout << endl << endl << "----------------------------------------------------------------------------" << endl;
    cout << "������� ����� m - ���������� ��������� �������: ";
    m = Read_int();

    if (m <= 0) {
        cerr << "������: ���������� ��������� ������ ���� �������������!" << endl;
        return 1;
    }

    cout << endl << "������� " << m << " �������� ��������� ������� ����� ������: ";
    for (int i = 0; i < m; ++i) {
        int j = Read_int();
        Add(j, p1, p2);
    }

    cout << endl << endl << "������� ����� n (n>0) - ���������� ���������" << endl;
    cout << "�������, ������� ����� ������� �� �������: ";
    n = Read_int();

    if (n <= 0) {
        cerr << "������: ���������� ����������� ��������� ������ ���� �������������!" << endl;
        return 1;
    }

    if (int error = Show_Before(p1)) {
        return error;
    }

    if (int error = Delete(n, p1)) {
        return error;
    }

    Show_After(p1);
    return 0;
}