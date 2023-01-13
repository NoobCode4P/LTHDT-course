#pragma once
#include "BusinessGate.h"
#include "AcademicGate.h"
#include "PowerGate.h"
#include <vector>

class Castle{
    vector <Gate*> a;
public:
    ~Castle();
    void nhapDS();
    bool cuuCongChua(Prince&);
};