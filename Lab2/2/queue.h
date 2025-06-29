#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

typedef Node* PNode;

void Add(int data, PNode& Head, PNode& Tail);
int Show_Before(PNode head);  
int Delete(int m, PNode& Head);  
void Show_After(PNode head);
int Read_int();
int RunQueueOperations(); 

#endif