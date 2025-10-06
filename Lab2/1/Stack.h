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

    Node* top_node;
    int element_count;

public:
    Stack();
    ~Stack();

    void add_node(int new_node_value);
    void delete_top();
    void show_stack() const;
};

#endif
