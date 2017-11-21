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
        while (current != 0)
        {
            if ((x == current->get_x()) && (y == current->get_y()) && (z == current->get_z()))
            {
                current->coff_ += coff;
                match = true;
            }
            current = current->next_;
        }
        if (!match)
        {
            PolyNode *newNode = new PolyNode(coff, x, y, z);
            newNode->next_ = first;
            first = newNode;
        }
    }
    else first = new PolyNode(coff, x, y, z);
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
    while (current != 0)
    {
        if ((x == current->get_x()) && (y == current->get_y()) && (z == current->get_z()))
        {
            cout << "retCoeff("<<x<<", "<<y<<", "<<z<<") = "<<current->get_coff() << endl;
            match = true;
        }
        current = current->next_;
    }
    if (!match)
    {
        cout << "no match" << endl;
    }
    cout << endl;
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
    while (current != 0)
    {
        current->exp_x += x;
        current->exp_y += y;
        current->exp_z += z;
        current = current->next_;
    }
    cout << endl;
}
void PolyList::printList()
{
    if (first == 0)
    {
        cout << "PolyList is empty.\n";
        return;
    }

    PolyNode *current = first;
    while (current != 0)
    {
        cout << current->get_coff() << "*";
        cout << "x^" << current->get_x();
        cout << "y^" << current->get_y();
        cout << "z^" << current->get_z();
        cout << endl;
        current = current->next_;
    }
    cout << endl;
}

// operation (PolyNode)
int PolyNode::get_coff()
{
    return coff_;
}
int PolyNode::get_x()
{
    return exp_x;
}
int PolyNode::get_y()
{
    return exp_y;
}
int PolyNode::get_z()
{
    return exp_z;
}