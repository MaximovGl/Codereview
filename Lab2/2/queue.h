#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
public:
    int getData() const { return data; }
    void setData(int newData) { data = newData; }
    Node* getNext() const { return next; }
    void setNext(Node* newNext) { next = newNext; }
};

typedef Node* PNode;

void add_node(int data, PNode& head, PNode& tail);
void show_initial_queue(PNode head);
void delete_n_elements(int n, PNode& head);
void show_new_queue(PNode head);
PNode input(int& n);

#endif
