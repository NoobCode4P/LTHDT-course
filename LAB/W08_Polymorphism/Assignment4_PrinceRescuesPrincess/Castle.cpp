#include "Castle.h"

Castle::~Castle(){
    while (!a.empty()){
        Gate* tmp = a.back();
        a.pop_back();
        delete tmp;
    }
}

void Castle::nhapDS(){
    int socong;
    cout << "Nhap so luong cong: "; cin >> socong;
    
    for (int i = 0; i < socong; i++){
        cout << "****Cong thu " << i + 1 << endl;
        int cong;
        do{
            cout << "Nhap loai cong [1(Giao Thuong), 2(Hoc Thuat), 3(Suc Manh)]: ";
            cin >> cong;
        }while (cong != 1 && cong != 2 && cong != 3);

        Gate* g = NULL;
        switch (cong){
            case 1:
                g = new BusinessGate;
                break;
            case 2:
                g = new AcademicGate;
                break;
            case 3:
                g = new PowerGate;
                break;
        }
        g->nhap();
        a.push_back(g);
    }
}

bool Castle::cuuCongChua(Prince& ht){
    for (int i = 0; i < a.size(); i++)
        if (!a[i]->quaCong(ht))
            return false;
    return true;
}