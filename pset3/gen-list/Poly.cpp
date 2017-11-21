// Poly.cpp
#include <iostream>
#include "Poly.h"

using namespace std;
// operation (PolyList)
void PolyList::push(int coff, int x, int y, int z)
{
    bool match = false;
    if (first)
    {
        PolyNode *current = first;
        while (current->next_ != 0)
        {
            current = current->next_;
            if (x == current->get_exp())
            {
                current = current->down_;
                while (current->next_ != 0)
                {
                    current = current->next_;
                    if (y == current->get_exp())
                    {
                        current = current->down_;
                        while (current->next_ != 0)
                        {
                            current = current->next_;
                            if (z == current->get_exp())
                            {
                                current->coff_ += coff;
                                cout << current->get_coff() << endl;
                                match = true;
                            }
                        }
                        // no match z exp
                        if (!match)
                        {
                            PolyNode *pnode6 = new PolyNode(no, coff, z);
                            current->next_ = pnode6;
                        }
                    }
                }
                // no match y exp
                if (!match)
                {
                    PolyNode *pnode5 = new PolyNode(var, 'z');
                    PolyNode *pnode4 = new PolyNode(ptr, y);
                    PolyNode *pnode6 = new PolyNode(no, coff, z);
                    current->next_ = pnode4;
                    pnode4->down_ = pnode5;
                    pnode5->next_ = pnode6;
                }
                
            }
        }
        // no match x exp
        if (!match)
        {
            PolyNode *pnode3 = new PolyNode(var, 'y');
            PolyNode *pnode5 = new PolyNode(var, 'z');
            PolyNode *pnode2 = new PolyNode(ptr, x);
            PolyNode *pnode4 = new PolyNode(ptr, y);
            PolyNode *pnode6 = new PolyNode(no, coff, z);
            current->next_ = pnode2;
            pnode2->down_ = pnode3;
            pnode3->next_ = pnode4;
            pnode4->down_ = pnode5;
            pnode5->next_ = pnode6;
        }
    }
    else
    {
        first = new PolyNode(var, 'x');
        PolyNode *pnode3 = new PolyNode(var, 'y');
        PolyNode *pnode5 = new PolyNode(var, 'z');
        PolyNode *pnode2 = new PolyNode(ptr, x);
        PolyNode *pnode4 = new PolyNode(ptr, y);
        PolyNode *pnode6 = new PolyNode(no, coff, z);
        first->next_ = pnode2;
        pnode2->down_ = pnode3;
        pnode3->next_ = pnode4;
        pnode4->down_ = pnode5;
        pnode5->next_ = pnode6;
    }
}
void PolyList::retCoeff(int x, int y, int z)
{
    bool match = false;
    if (first == 0)
    {
        cout << "PolyList is empty.\n";
        return;
    }

    PolyNode *current = first;
    while (current->next_ != 0)
    {
        current = current->next_;
        if (x == current->get_exp())
        {
            current = current->down_;
            while (current->next_ != 0)
            {
                current = current->next_;
                if (y == current->get_exp())
                {
                    current = current->down_;
                    while (current->next_ != 0)
                    {
                        current = current->next_;
                        if (z == current->get_exp())
                        {
                            cout << "retCoeff("<<x<<", "<<y<<", "<<z<<") = "<<current->get_coff() << endl;
                            match = true;
                        }
                    }
                }
            }
        }
    }
    if (!match)
    {
        cout << "no match" << endl;
    }
}
void PolyList::Mulf(int x, int y, int z)
{
    if (first == 0)
    {
        cout << "PolyList is empty.\n";
        return;
    }

    cout << "Mulf("<<x<<", "<<y<<", "<<z<<")" << endl;
    PolyNode *current = first;
    while (current->next_ != 0)
    {
        current = current->next_;
        current->exp_ += x;
        if (current->down_ != 0)
        {
            PolyNode *current2 = current->down_;
            while (current2->next_ != 0)
            {
                current2 = current2->next_;
                current2->exp_ += y;
                if (current->down_ != 0)
                {
                    PolyNode *current3 = current2->down_;
                    while (current3->next_ != 0)
                        current3 = current3->next_;
                        current3->exp_ += z;
                }
            }
        }
    }
}
PolyList::~PolyList()
{
    cout << "Destruct polylist" << endl;
}
// operation (PolyNode)
PolyNode::PolyNode(Triple trio, char vble)
{
    trio_ = trio;
    vble_ = vble;
    exp_ = 0;
    next_ = 0;
}

PolyNode::PolyNode(Triple trio, int exp)
{
    trio_ = trio;
    down_ = 0;
    exp_ = exp;
    next_ = 0;
}

PolyNode::PolyNode(Triple trio, int coff, int exp)
{
    trio_ = trio;
    coff_ = coff;
    exp_ = exp;
    next_ = 0;
}
int PolyNode::get_coff()
{
    return coff_;
}
int PolyNode::get_exp()
{
    return exp_;
}
PolyNode::~PolyNode()
{
    cout << "Destruct polynode" << endl;
}