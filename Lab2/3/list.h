#ifndef LIST_H
#define LIST_H

class SortedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int size;

public:
    SortedList();
    ~SortedList();
    void append(int value);
    void insert_sorted(int value);
    void remove(int value);
    bool contains(int value) const;
    void display() const;
    SortedList create_copy() const;
};

void run_task();

#endif
