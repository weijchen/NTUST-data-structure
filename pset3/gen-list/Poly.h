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
    ~PolyList();
};

enum Triple { var, ptr, no };
class PolyNode
{
friend class PolyList;
private:
    Triple trio_;
    union
    {
        char vble_;
        PolyNode *down_;
        int coff_;
    };
    int exp_;
    PolyNode *next_;
public:
    PolyNode():trio_(var), exp_(0), next_(0){};
    PolyNode(Triple trio, char vble);
    PolyNode(Triple trio, int exp);
    PolyNode(Triple trio, int coff, int exp);
    int get_coff();
    int get_exp();
    ~PolyNode();
};
#endif