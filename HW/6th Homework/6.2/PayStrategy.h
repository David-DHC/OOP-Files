#pragma once

class PayStrategy
{

public:

    virtual float pay(float) = 0;
};


class NormalStrategy : public PayStrategy
{

public:

    float pay(float a)
    {
        return a;
    }

};

class RebateStrategy : public PayStrategy
{

public:

    float pay(float a)
    {
        return 0.38 * a;
    }

};

class ReturnStrategy : public PayStrategy
{

public:

    float pay(float a)
    {
        if (a >= 25)
            return a - 10;
        else
            return a;
    }

};
