#include "SavingBankAccount.h"

void SavingBankAccount::input(){
    BankAccount::input();
    double interest;
    ui period, numOfsavingMonths;
    cout << "Enter annual interest rate: "; cin >> interest;
    cout << "Enter period: "; cin >> period;
    cout << "Enter number of saving months: "; cin >> numOfsavingMonths;

    this->interestRate = interest;
    this->period = period;
    this->savingMonths = numOfsavingMonths;
}

void SavingBankAccount::output(){
    BankAccount::output();
    cout << "Balance added with interest: " << currentBalance() << endl;
    cout << "Annual interest rate: " << currentInterest() << endl;
    cout << "Period: " << period << endl;
    cout << "Number of saving months until now: " << savingMonths << endl;
}

void SavingBankAccount::deposit(ull money){
    if (savingMonths >= period)
        BankAccount::deposit(money);
    else{
        cout << "Would you like to create a new saving bank account?" << endl;
    }
}

ull SavingBankAccount::withdraw(ull money){
    if (savingMonths >= period){
        if (savingMonths % period == 0){
            double rate = 1 + interestRate / 12 * period;
            return (ull)((double)BankAccount::withdraw(money) * rate);
        }
        return withdrawImmediate(money);
    }
    return 0;
}

ull SavingBankAccount::withdrawImmediate(ull money){
    interestRate = 0.02;
    ull withdrawAmount = BankAccount::withdraw(money);
    return (ull)((double)withdrawAmount * (1 + interestRate / 12 * (savingMonths % period)));
}

ull SavingBankAccount::currentBalance(){
    if (savingMonths < period)
        return BankAccount::currentBalance();

    double rate = pow(1 + interestRate / 12 * period, savingMonths / period);
    balance = (ull)((double)balance * rate);
    return balance;
}

double SavingBankAccount::currentInterest(){
    return interestRate;
}