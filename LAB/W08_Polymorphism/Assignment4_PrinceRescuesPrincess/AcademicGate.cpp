#include "AcademicGate.h"

void AcademicGate::nhap(){
    cout << "=======Nhap thong tin cho cong Hoc Thuat=======" << endl;
    int tt;
    cout << "Nhap chi so tri tue: "; cin >> tt;

    this->tritue = tt;
}

bool AcademicGate::quaCong(Prince& ht){
    return ht.getTriTue() >= tritue;
}