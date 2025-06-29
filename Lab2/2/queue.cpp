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
        cerr << "Ошибка: попытка показать пустую очередь!" << endl;
        return 1;
    }

    PNode temp = head;
    cout << endl << "Исходный адрес первого элемента: " << head << " " << head->data;

    cout << endl << "Исходная очередь: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    PNode last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    cout << endl << "Исходный адрес последнего элемента: " << last << " " << last->data << endl;
    return 0;
}

int Delete(int m, PNode& Head) {
    if (m < 0) {
        cerr << "Ошибка: количество удаляемых элементов не может быть отрицательным!" << endl;
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
        cout << "Очередь после удаления элементов оказалась пустой" << endl;
        cout << "Начало очереди: nullptr" << endl;
        cout << "Конец очереди: nullptr" << endl;
    }
    else {
        PNode temp2 = head;
        cout << "Новое начало очереди: " << temp2 << " " << temp2->data << endl;
        cout << "Оставшиеся элементы очереди: ";
        PNode current = head;
        PNode last = nullptr;
        while (current != nullptr) {
            last = current;
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl << "Новый конец очереди: " << last << " " << last->data << endl;
    }
}

int Read_int() {
    int m = 0;
    while (!(cin >> m)) {
        cerr << "Ошибка ввода! Пожалуйста, введите целое число: ";
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

    cout << "Добро пожаловать!" << endl;
    cout << "Перед нами новая задача:" << endl;
    cout << "Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди." << endl;
    cout << "Извлечь из очереди N начальных элементов" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Вам необходимо ввести количество элементов очереди и их значения через пробел " << endl;
    cout << "Мы выведем новые адреса начала и конца очереди, извлечем n значений и выведем на экран" << endl;
    cout << endl << endl << "----------------------------------------------------------------------------" << endl;
    cout << "Введите число m - количество элементов очереди: ";
    m = Read_int();

    if (m <= 0) {
        cerr << "Ошибка: количество элементов должно быть положительным!" << endl;
        return 1;
    }

    cout << endl << "Введите " << m << " значений элементов очереди через пробел: ";
    for (int i = 0; i < m; ++i) {
        int j = Read_int();
        Add(j, p1, p2);
    }

    cout << endl << endl << "Введите число n (n>0) - количество элементов" << endl;
    cout << "очереди, которые нужно извлечь из очереди: ";
    n = Read_int();

    if (n <= 0) {
        cerr << "Ошибка: количество извлекаемых элементов должно быть положительным!" << endl;
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