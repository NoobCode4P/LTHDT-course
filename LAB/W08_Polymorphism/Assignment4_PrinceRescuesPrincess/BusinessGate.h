#pragma once
#include "Gate.h"

class BusinessGate : public Gate{
    int dongia;
    int sohang;
public:
    void nhap();
    bool quaCong(Prince&);
};