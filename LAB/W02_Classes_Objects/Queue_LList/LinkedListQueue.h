#include <iostream>
using namespace std;

class Node{
public:
    int key;
    Node *next;

    Node();
    Node(int);
};

class LinkedListQueue{
    Node *head, *tail;
    int capacity;
    int num;

public:
    void init(int);
    void enqueue(int);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
    void printQueue();
};

