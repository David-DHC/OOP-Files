#pragma once
#include "LoadStrategy.h"
#include "PayStrategy.h"

class Calculator
{

private:
    LoadStrategy *Load;
    PayStrategy *Pay;

public:
    Calculator (LoadStrategy* a, PayStrategy* b): Load(a), Pay(b) {}

    float load ()
    {
        return Load->load();
    }

    float pay (float m)
    {
        return Pay->pay(m);
    }

};