#pragma once
#include <iostream>
using namespace std;

class Prince{
    int tien;
    int tritue;
    int sucmanh;
public:
    void nhap();
    void xuat();
    int getTien();
    int getTriTue();
    int getSucManh();
    void setTien(int tien);
    void setSucManh(int sucmanh);
};