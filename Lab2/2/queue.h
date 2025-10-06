#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    
    Node* front_node;
    Node* back_node;
    int element_count;

public:
    Queue();
    ~Queue();
    void enqueue(int value);
    void dequeue();
    bool is_empty() const;
    int get_front() const;
    int get_size() const;
    void display_initial() const;
    void remove_first_n_elements(int n);
    void display_after_removal() const;
};

Queue create_queue_from_input(int& elements_to_remove);

#endif
