#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void append(int value);
    bool remove_value(int value);
    void display() const;
    void write_to_file_and_clear(const std::string& filename);
    void clear();
};

int read_integer_input();
void display_file_contents(const std::string& filename);
void execute_linked_list_workflow();

#endif
