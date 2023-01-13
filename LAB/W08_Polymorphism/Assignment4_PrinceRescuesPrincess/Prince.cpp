#include "Prince.h"

void Prince::nhap() {
    int t, tt, sm;
    cout << "======Nhap thong so cua hoang tu======" << endl;
    cout << "Nhap so tien: "; cin >> t;
    cout << "Nhap chi so tri tue: "; cin >> tt;
    cout << "Nhap chi so suc manh: "; cin >> sm;

    this->tien = t;
    this->tritue = tt;
    this->sucmanh = sm;
}

void Prince::xuat() {
    cout << "So tien: " << tien << endl;
    cout << "Chi so tri tue: " << tritue << endl;
    cout << "Chi so suc manh: " << sucmanh << endl;
}

int Prince::getTien() {
    return tien;
}

int Prince::getTriTue() {
    return tritue;
}

int Prince::getSucManh() {
    return sucmanh;
}

void Prince::setTien(int tien) {
    this->tien = tien;
}

void Prince::setSucManh(int sucmanh){
    this->sucmanh = sucmanh;
}