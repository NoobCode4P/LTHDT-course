#include "Worker.h"

Worker::Worker(){}

Worker::Worker(string id, string fullname, string addr) : Employee(id, fullname, addr){
	numOfItem = 0;
}

Worker::Worker(string id, string fullname, string addr, int numOfItem) : Employee(id, fullname, addr){
	this->numOfItem = numOfItem;
}

Worker::Worker(const Employee& a) : Employee(a){
	numOfItem = 0;
}

Worker::Worker(const Worker& a) : Employee(a){
	numOfItem = a.numOfItem;
}

void Worker::input(){
	Employee::input();
	int n;
	cout << "Enter number of produced items: ";
	cin >> n;
	numOfItem = n;
}

void Worker::output(){
	Employee::output();
	cout << "Number of produced items: " << numOfItem << endl;
	cout << "Salary per month: " << salary() << endl;
}

ull Worker::salary(){
	return Employee::salary() + numOfItem * 20000;
}
