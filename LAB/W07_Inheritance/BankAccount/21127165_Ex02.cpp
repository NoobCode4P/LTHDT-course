#include "SavingBankAccount.h"

int main(){
    SavingBankAccount a;
    a.input();
    cout << "==========Data=========" << endl;
    a.output();
    cout << "=======================" << endl;

    int choice;
    do {
        cout << "Press 1 for deposit, 2 for withdrawal: ";
        cin >> choice;
    }while (choice != 1 && choice != 2);

    ull deposit, withdrawal;
    switch(choice){
        case 1:{
            cout << "Enter the amount of deposit: ";
            cin >> deposit;
            a.deposit(deposit);
            break;
        }
        case 2:{
            cout << "Enter the amount of withdrawal: ";
            cin >> withdrawal;
            ull withdrawWithInterest = a.withdraw(withdrawal);
            if (withdrawWithInterest == 0)
                cout << "Error: You are not allowed to withdraw before period/ The amount of withdrawn money exceeds the current balance!" << endl;
            else 
                cout << "Withdrawn amount including interest: " << withdrawWithInterest << endl;
            break;
        }
    }
    cout << "==========Data=========" << endl;
    a.output();
    cout << "=======================" << endl;

    return 0;
}