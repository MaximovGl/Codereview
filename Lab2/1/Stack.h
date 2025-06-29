#ifndef STACK_H
#define STACK_H

class Node {
public:
    int x;
    Node* next;
    Node(int d);
};

class Stack {
private:
    Node* top;

public:
    Stack();
    void Push(int d);
    void Show() const;
    void ShowAddress() const;
    int GetTopValue() const;
    bool IsEmpty() const;
};

int Read_int();
void RunStackOperations(Stack& stack);  

#endif 