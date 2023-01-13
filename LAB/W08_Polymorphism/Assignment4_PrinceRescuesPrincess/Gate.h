#pragma once
#include "Prince.h"

class Gate{
public:
    virtual void nhap() = 0;
    virtual bool quaCong(Prince&) = 0;
};