#include "BusinessGate.h"

void BusinessGate::nhap(){
    cout << "=======Nhap thong tin cho cong Giao Thuong========" << endl;
    int dg, sh;
    cout << "Nhap don gia: "; cin >> dg;
    cout << "Nhap so hang: "; cin >> sh;

    this->dongia = dg;
    this->sohang = sh;
}

bool BusinessGate::quaCong(Prince& ht){
    if (ht.getTien() < dongia * sohang)
        return false;
    ht.setTien(ht.getTien() - dongia * sohang);
    return true;
}