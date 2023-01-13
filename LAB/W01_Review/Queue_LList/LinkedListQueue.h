#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *next;

    Node(){
        next = NULL;
    }
    Node(int key){
        this->key = key;
        this->next = NULL;
    }
};

struct LinkedListQueue{
    Node *head, *tail;
    int capacity;
    int num;

    void init(int);
    void enqueue(int);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
};

void printQueue(LinkedListQueue);