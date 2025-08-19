#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* p1;
    int counter;

public:
    Stack();
    ~Stack();

    void add_node(int new_node_value);
    void delete_top();
    void show_stack() const;
};

#endif
