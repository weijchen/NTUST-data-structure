//============================================================================
// Name        : pset3.cpp
// Author      : Jimmy
// Description : Generalized list for polynomial operations
//============================================================================
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
// #include "Poly.h"

using namespace std;

vector <string> tokenizer(string input);

int main()
{
    // Enter polynomials
    int x, y, z;
    int i = 0;
    bool enter = true;
    while(enter)
    {
        string input;
        vector <string> ans;
        cout << "Enter coefficient and exponents (coff, x, y, z) > ";
        getline(cin, input);
        input += ' ';

        ans = tokenizer(input);

        for (int i = 0; i <= ans.size(); i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;

        Polylist plis;
        Polynode pnode;
    }

    while (true)
    {
        if (inptr = 'ret')
        {
            retCoeff()
        }
        else if (inptr = 'mul')
        {
            Mulf()
        }
    }

    // polyno poly1;
    
    return 0;
};






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