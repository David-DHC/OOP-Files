#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <bits/stdc++.h>
using namespace std;

template<class A, class C>
class Container : public BasicContainer<A>
{
    C base;
public:
    void insert(const A &x)
    {
        for (auto t = base.begin(); t != base.end(); ++t)
        {
            if (*t > x)
            {
                base.insert(t, x);
                return;
            }
        }
        base.insert(base.end(), x);
    }

    A find(int k)
    {
        auto t = base.begin();
        while (--k)
            ++t;
        return *t;
    }
};

template<class A>
class Container<A, vector<A>> : public BasicContainer<A>
{
public:
    vector<A> base;
    bool finding = false;

    void insert(const A &x)
    {
        base.push_back(x);
    }

    A find(int k)
    {
        if (!finding)
        {
            finding = true;
            sort(base.begin(), base.end());
        }

        return base[k - 1];
    }
};

template<class A>
class Container<A, multiset<A>> : public BasicContainer<A>
{
public:
    multiset<A> base;
    bool finding = false;

    void insert(const A &x)
    {
        base.insert(x);
    }

    A find(int k)
    {
        int times = 0;
        for (A i : base)
        {
            times++;
            if (times == k)
                return i;
        }
    }
};
#endif
/*
vector string
14
insert fahfaewh
insert asdfhaew
insert alshg
insert qeovznz
insert asofhaw
insert owuhejf
insert zosierh
find 1
find 2
find 3
find 4
find 5
find 6
find 7
*/