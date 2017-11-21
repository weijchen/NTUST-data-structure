// Poly.h
#ifndef POLY_H_
#define POLY_H_

using namespace std;

class PolyNode;

class PolyList
{
friend class PolyNode;
private:
    PolyNode *first_;
public:
    // methods
    PolyList();
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
        int coef_;
    };
    int exp_;
    PolyNode *next_;
public:
    // PolyNode(Triple trio, char vble_);
    // PolyNode(Triple trio, int exp, PolyNode *next);
    PolyNode(Triple trio, char vble, int exp);
    PolyNode(Triple trio, int exp);
    PolyNode(Triple trio, int coef, int exp);
};
#endif

            
// struct GList { Data d; struct GList* next; }

// class Data {
//         public:
//             Data(double n);
//             Data(string s);
//             Data(struct GList list);
//         }
