#pragma once
#include "Gate.h"

class PowerGate : public Gate{
    int sucmanh;
public:
    void nhap();
    bool quaCong(Prince&);
};