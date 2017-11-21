// Poly.h
#ifndef POLY_H_
#define POLY_H_

using namespace std;

class PolyNode;

class PolyList
{
private:
    PolyNode *first;
public:
    // methods
    PolyList():first(0){};
    void push(int coff, int x, int y, int z);
    void retCoeff(int x, int y, int z);
    void Mulf(int x, int y, int z);
    void printList();
};

class PolyNode
{
friend class PolyList;
private:
    int coff_;
    int exp_x;
    int exp_y;
    int exp_z;
    PolyNode *next_;
public:
    PolyNode():coff_(0), exp_x(0), exp_y(0), exp_z(0), next_(0){};
    PolyNode(int coff, int x, int y, int z):coff_(coff), exp_x(x), exp_y(y), exp_z(z), next_(0){};
    int get_coff();
    int get_x();
    int get_y();
    int get_z();
};
#endif