

#include "linked_list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cctype> 

using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::append(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void LinkedList::deleteNode(Node* nodeToDelete) {
    if (nodeToDelete == nullptr) {
        cerr << "������: ������� ������� �������������� ����" << endl;
        return;
    }

    Node* prevNode = nodeToDelete->prev;
    Node* nextNode = nodeToDelete->next;

    if (prevNode != nullptr) {
        prevNode->next = nextNode;
    }
    else {
        head = nextNode;
    }

    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    }

    delete nodeToDelete;
}

void LinkedList::print() const {
    Node* current = head;
    cout << "������: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::writeToFileAndClear(const std::string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "������ �������� �����!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }

    bool firstElement = true;
    while (current != nullptr) {
        if (firstElement) {
            file << current->data;
            firstElement = false;
        }
        else {
            file << " " << current->data;
        }

        Node* prevNode = current->prev;
        deleteNode(current);
        current = prevNode;
    }

    file.close();
    cout << "������ �������� � ���� � ������ ������." << endl;
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

int inputNumber() {
    string input;
    while (true) {
        cout << "������� ����� (��� '-1' ��� ����������): ";
        cin >> input;

        if (input == "-1") {
            return -1;
        }

        bool isValid = true;
        int sign = 1;
        size_t start = 0;

        if (input.empty()) {
            isValid = false;
        }
        else if (input[0] == '-') {
            sign = -1;
            start = 1;
            if (input.size() == 1) isValid = false;
        }

        for (size_t i = start; i < input.size(); ++i) {
            if (!isdigit(input[i])) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            int number = 0;
            for (size_t i = start; i < input.size(); ++i) {
                number = number * 10 + (input[i] - '0');
            }
            return number * sign;
        }
        else {
            cerr << "������������ ����! ����������� ����� � ���� '-' � ������." << endl;
        }
    }
}

void printFileContents(const std::string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "������ ��� �������� ����� ��� ������!" << endl;
        return;
    }

    cout << "\n=== ���������� ����� ===" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void processLinkedListWork() {
    LinkedList list;

    cout << "=== ���� ����� � ������ ===" << endl;
    while (true) {
        int number = inputNumber();
        if (number == -1) break;
        list.append(number);
    }

    list.print();

    cout << "\n=== ������ � ���� ===" << endl;
    string filename;
    cout << "������� ��� �����: ";
    cin >> filename;

    list.writeToFileAndClear(filename);
    printFileContents(filename);
    list.clear();
}