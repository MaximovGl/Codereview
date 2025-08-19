#include "queue.h"

void add_node(int data, PNode& head, PNode& tail) {
    PNode temporary_node;
    if (head == NULL) {
        head = new Node;
        tail = head;
        head->setNext(NULL);
    }
    else {
        temporary_node = new Node;
        tail->setNext(temporary_node);
        tail = temporary_node;
        tail->setNext(NULL);
    }
    tail->setData(data);
}

void show_initial_queue(PNode head) {
    PNode temporary_node = head;
    cout << endl << "Исходный адрес первого элемента: " << head << " " << head->getData();
    cout << endl << "Исходная очередь: ";
    while (temporary_node != nullptr) {
        cout << temporary_node->getData() << " ";
        temporary_node = temporary_node->getNext();
    }
    PNode last = head;
    while (last->getNext() != nullptr) {
        last = last->getNext();
    }
    cout << endl << "Исходный адрес последнего элемента: " << last << " " << last->getData() << endl;
}

void delete_n_elements(int n, PNode& head) {
    PNode temporary_node;
    for (int i = 0; i < n; i++) {
        if (head == nullptr)
            break;
        temporary_node = head;
        cout << temporary_node->getData() << " " << temporary_node->getNext() << " ";
        head = head->getNext();
        delete temporary_node;
        cout << endl;
    }
    cout << endl;
}

void show_new_queue(PNode head) {
    PNode temporary_node = nullptr;
    PNode temp2 = head;
    if (head == nullptr) {
        cout << "Очередь после удаления элементов оказалась пустой" << endl;
        int* pointer = nullptr;
        cout << "Начало очереди: " << pointer << endl;
        cout << "Конец очереди: " << pointer << endl;
    }
    else {
        cout << "Новое начало очереди: " << temp2 << " " << temp2->getData() << endl;
        cout << "Оставшиеся элементы очереди: ";
        while (head != nullptr) {
            temporary_node = head;
            cout << temporary_node->getData() << " ";
            head = head->getNext();
        }
        cout << endl << "Новый конец очереди: " << temporary_node << " " << temporary_node->getData() << endl;
    }
}

PNode input(int& n) {
    int m;
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
    cin >> m;
    if (cin.fail() || m <= 0) {
        cerr << "Ошибка ввода: m должно быть положительным целым числом." << endl;
        exit(1);
    }
    cout << endl << "Введите " << m << " значений элементов очереди через пробел ";
    for (int i = 0; i < m; i++) {
        int j;
        cin >> j;
        if (cin.fail()) {
            cerr << "Ошибка ввода: элемент очереди должен быть целым числом." << endl;
            exit(1);
        }
        add_node(j, p1, p2);
    }
    cout << endl << endl << "Введите число n(n>0) - количество элементов" << endl;
    cout << "очереди, которые нужно извлечь из очереди: ";
    cin >> n;
    if (cin.fail() || n <= 0) {
        cerr << "Ошибка ввода: n должно быть положительным целым числом." << endl;
        exit(1);
    }
    return p1;
}
