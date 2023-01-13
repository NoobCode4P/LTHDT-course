#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned int ui;
typedef unsigned long long ull;

class BankAccount{
protected:
    ui accountNum;
    string name;
    string id;
    ull balance;
public:
    virtual void input();
    virtual void output();

    virtual void deposit(ull money);
    virtual ull withdraw(ull money);
    virtual ull currentBalance();
};