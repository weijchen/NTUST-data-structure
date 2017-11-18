// Poly.h
#ifndef POLY_H_
#define POLY_H_

using namespace std;


class PolyList
{
private:
    PolyNode *first;
public:
    // methods
}

enum Triple{ var, ptr, no };
class PolyNode
{
friend class PolyList;

private:
    Triple trio;
    union
    {
        char vble;
        PolyNode *down;
        int coef;
    };
    int exp;
    PolyNode *next;
public:
    Polynode(trio, )
};
#endif

            
            
struct GList { Data d; struct GList* next; }

class Data {
        public:
            Data(double n);
            Data(string s);
            Data(struct GList list);
        }
