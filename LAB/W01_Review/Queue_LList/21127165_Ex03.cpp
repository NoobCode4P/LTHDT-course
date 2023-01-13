#include "LinkedListQueue.h"
#include <ctime>

int main(){
    int capac;
    cout << "Enter capacity: "; cin >> capac;
    const int max = 50;
    const int min = 1;

    LinkedListQueue q;
    q.init(capac);

    srand(time(0));
    while (!q.isFull()) {
        int x = rand() % (max - min) + 1;
        q.enqueue(x);
    }
    printQueue(q);
    cout << "The top element: " << q.peek() << endl;
    cout << "==============" << endl;
    int a;
    cout << "Add 1 more element to the queue: "; cin >> a;
    q.enqueue(a);

    cout << "=============\nDequeuing....." << endl;
    while (!q.isEmpty()){
        int x = q.dequeue();
        cout << x << " ";
    }
    cout << endl;

    cout << "=============\nGenerating another Queue..." << endl;
    while (!q.isFull()) {
        int x = rand() % (max - min) + 1;
        q.enqueue(x);
    }
    printQueue(q);
    
    cout << "Clearing the queue..." << endl;
    q.clear();
    printQueue(q);
    

    return 0;
}