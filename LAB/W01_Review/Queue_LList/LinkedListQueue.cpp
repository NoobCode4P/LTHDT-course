#include "LinkedListQueue.h"

void LinkedListQueue::init(int capac){
    head = tail = NULL;
    capacity = capac;
    num = 0;
}

void LinkedListQueue::enqueue(int x){
    if (isFull()){
        cout << "The queue is full" << endl;
        return;
    }
    Node *newNode = new Node(x);
    if (tail == NULL)
        head = tail = newNode;
    else{
        tail->next = newNode;
        tail = newNode;
    }
    num++;
}

int LinkedListQueue::dequeue(){
    if (head == NULL)
        return -9999;
    Node *tmp = head;
    int data = tmp->key;
    head = tmp->next;

    if (head == NULL)
        tail = NULL;

    delete tmp;
    num--;
    return data;
}

int LinkedListQueue::peek(){
    if (head == NULL)
        return -9999;
    return head->key;
}

bool LinkedListQueue::isEmpty(){
    return head == NULL || tail == NULL || num == 0;
}

bool LinkedListQueue::isFull(){
    return num == capacity;
}

void LinkedListQueue::clear(){
    if (head == NULL)
        return;
    
    Node *iter = head;
    while (iter){
        Node *tmp = iter;
        iter = iter->next;
        delete tmp;
        num--;
    }
    head = tail = NULL;
}

void printQueue(LinkedListQueue q){
    if (q.isEmpty())
        cout << "Empty queue!" << endl;
    else {
        Node *iter = q.head;
        while (iter){
            cout << iter->key << " ";
            iter = iter->next;
        }
        cout << endl;
    }
}