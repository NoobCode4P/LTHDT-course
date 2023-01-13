#include "BankAccount.h"

class SavingBankAccount : public BankAccount{
    double interestRate;
    ui period;
    ui savingMonths;    
public:
    void input();
    void output();

    void deposit(ull money);
    ull withdraw(ull money);
    ull withdrawImmediate(ull money);
    ull currentBalance();
    double currentInterest();
};