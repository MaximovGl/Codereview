#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <locale>

struct Node {
    int data;        
    Node* prev;      
    Node* next;      
};

class LinkedList {
private:
    Node* head;      

public:
    LinkedList();    
    ~LinkedList();   

    void append(int value);

    void deleteNode(Node* nodeToDelete);

    void print() const;

    void writeToFileAndClear(const std::string& filename);

    void clear();
};

int inputNumber();

void printFileContents(const std::string& filename);

void processLinkedListWork();

#endif 