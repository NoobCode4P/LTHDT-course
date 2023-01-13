#pragma once
#include "Gate.h"

class AcademicGate : public Gate {
    int tritue;
public:
    void nhap();
    bool quaCong(Prince&);
};