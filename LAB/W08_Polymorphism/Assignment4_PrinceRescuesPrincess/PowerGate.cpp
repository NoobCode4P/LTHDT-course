#include "PowerGate.h"

void PowerGate::nhap(){
    cout << "=====Nhap thong tin cho cong Suc Manh======" << endl;
    int sm;
    cout << "Nhap chi so suc manh: "; cin >> sm;

    this->sucmanh = sm;
}

bool PowerGate::quaCong(Prince& ht){
    if (ht.getSucManh() < sucmanh)
        return false;
    ht.setSucManh(ht.getSucManh() - sucmanh);
    return true;
}