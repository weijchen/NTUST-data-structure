// Poly.cpp
#include <iostream>
#include "Poly.h"

using namespace std;

PolyList::PolyList()
{
    PolyList *list;
    list->first_ = NULL;
}

PolyNode::PolyNode(Triple trio, char vble, int exp)
{
    trio_ = trio;
    vble_ = var;
    exp_ = exp;
    next_ = NULL;
}

PolyNode::PolyNode(Triple trio, int exp)
{
    trio_ = trio;
    down_ = NULL;
    exp_ = exp;
    next_ = NULL;
}

PolyNode::PolyNode(Triple trio, int coef, int exp)
{
    trio_ = trio;
    coef_ = coef;
    exp_ = exp;
    next_ = NULL;
}