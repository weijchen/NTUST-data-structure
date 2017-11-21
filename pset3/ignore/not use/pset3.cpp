//============================================================================
// Name        : pset3.cpp
// Author      : Jimmy
// Description : Generalized list for polynomial operations
//============================================================================
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Poly.h"
using namespace std;

vector <string> tokenizer(string input);
void createNode(vector <string> ans, PolyList &list);

int main()
{
    // Enter polynomials
    int x, y, z;
    int i = 0;
    bool enter = true;
    PolyList plist;
    while(enter)
    {

        string input;
        vector <string> ans;
        cout << "Enter coefficient and exponents (coff, x, y, z) > ";
        getline(cin, input);
        input += ' ';

        ans = tokenizer(input);
        createNode(ans, plist);

        for (int i = 0; i <= ans.size(); i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;

    }

    // while (true)
    // {
    //     if (inptr = 'ret')
    //     {
    //         retCoeff()
    //     }
    //     else if (inptr = 'mul')
    //     {
    //         Mulf()
    //     }
    // }

    // polyno poly1;
    
    return 0;
};


void createNode(vector <string> ans, PolyList list)
{
    if (list.first_ == NULL)
    {
        // PolyNode pnode1, pnode2, pnode3, pnode4, pnode5, pnode6;
        PolyNode pnode1(var, 'x', 0);
        PolyNode pnode3(var, 'y', 0);
        PolyNode pnode5(var, 'z', 0);
        PolyNode pnode2(ptr, ans[1]);
        PolyNode pnode4(ptr, ans[2]);
        PolyNode pnode6(no, ans[0], ans[3]);
        list.first_ = &pnode1;
        pnode1.next_ = &pnode2;
        pnode2.down_ = &pnode3;
        pnode3.next_ = &pnode4;
        pnode4.down_ = &pnode5;
        pnode5.next_ = &pnode6;
    }
    else
    {
        PolyNode current(var, 'x', 0);
        current = list.first_;
        while (current)
        {
            // whether exp of x match
            if (current.next_.exp_ != ans[1])
            {
                current = current.next_;
            }
            else
            {
                current = current->down_;
                while(current)
                {
                    if (current.next_.exp_ != ans[2])
                    {
                         current = current.next_;
                    }
                    else
                    {
                        current = current.down_;
                        while(current)
                        {
                            if (current.next_.exp_ != ans[3])
                            {
                                current = current.next_;
                            }
                            else
                            {

                            }
                            // create new z node
                            current.next_ = current;
                            PolyNode pnode6(no, ans[0], ans[3]);
                            current.next_ = pnode6;
                        }
                    }
    
                }
                // create new y node
                current.next_ = current;
                PolyNode pnode5(var, 'z', 0);
                PolyNode pnode4(ptr, ans[2]);
                PolyNode pnode6(no, ans[0], ans[3]);
                current.next_ = pnode4;
                pnode4.down_ = pnode5;
                pnode5.next_ = pnode6;
            }
        }
        // create new x node
        current.next_ = current;
        PolyNode pnode3(var, 'y', 0);
        PolyNode pnode5(var, 'z', 0);
        PolyNode pnode2(ptr, ans[1]);
        PolyNode pnode4(ptr, ans[2]);
        PolyNode pnode6(no, ans[0], ans[3]);
        current.next_ = pnode2;
        pnode2.down_ = pnode3;
        pnode3.next_ = pnode4;
        pnode4.down_ = pnode5;
        pnode5.next_ = pnode6;
    }
}


        


vector <string> tokenizer(string input)
{
    string output;
    vector <string> arr;
    for (int i = 0; i <= input.size(); i++)
        {
            if (input[i] != ' ')
            {
                output += input[i];
            }
            else
            {
                arr.push_back(output);
                output.clear();
            }
        }
    return arr;
};