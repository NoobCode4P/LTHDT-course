#include "BankAccount.h"

void BankAccount::input(){
    ui number;
    string name;
    string ID;
    ull deposit;
    cout << "Enter account number: ";
    cin >> number;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter ID: ";
    cin >> ID;
    cout << "Enter initial deposit: ";
    cin >> deposit;
    
    this->accountNum = number;
    this->name = name;
    this->id = ID;
    this->balance = deposit;
}

void BankAccount::output(){
    cout << "Account: " << accountNum << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Balance without interest: " << balance << endl;
}

void BankAccount::deposit(ull money){
    if (money > 0)
        balance += money;
}

ull BankAccount::withdraw(ull money){
    if (balance < 50000 + money){
        cout << "The balance should not be less than 50000 VND" << endl;
        return 0;
    }
    balance -= money;
    return money;
}

ull BankAccount::currentBalance(){
    return balance;
}