//============================================================================
// Name        : pset3.cpp
// Author      : Jimmy
// Description : Linked list for polynomial operations
//============================================================================
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Poly.h"

using namespace std;

vector <string> tokenizer(string input);

int main()
{
    bool enter = true, start = true;
    PolyList plist;
    while(enter)
    {
        string input;
        vector <string> ans;
        cout << "Enter coefficient and exponents (coff x y z), Q to quit > ";
        getline(cin, input);
        if (input == "Q" || input == "q")
        {
            enter = false;
        }
        else
        {
            input += ' ';
            ans = tokenizer(input);
            if (ans.size() != 4)
            {
                cout << "== Wrong input, retry ==" << endl;
            }
            else
            {
                plist.push(stoi(ans[0]), stoi(ans[1]), stoi(ans[2]), stoi(ans[3]));
            }
        }
    }

    while(start)
    {
        int func;
        cout << "===== Choose function =====" << endl;
        cout << "1. retCoeff(ex, ey, ez)" << endl;
        cout << "2. Mulf(ex, ey, ez)" << endl;
        cout << "3. printList()" << endl;
        cout << "0. Quit" << endl;
        cout << "> ";
        cin >> func;
        if (func == 1)
        {
            cin.ignore(256, '\n');
            string input;
            vector <string> first_ans;
            cout << "Enter (ex ey ez) > ";
            getline(cin, input);
            input += ' ';
            first_ans = tokenizer(input);
            if (first_ans.size() != 3)
            {
                cout << "== Wrong input, retry ==" << endl;
            }
            else
            {
                plist.retCoeff(stoi(first_ans[0]), stoi(first_ans[1]), stoi(first_ans[2]));
            }
        }
        else if (func == 2)
        {
            cin.ignore(256, '\n');
            string input;
            vector <string> second_ans;
            cout << "Enter (ex ey ez) > ";
            getline(cin, input);
            input += ' ';
            second_ans = tokenizer(input);
            if (second_ans.size() != 3)
            {
                cout << "== Wrong input, retry ==" << endl;
            }
            else
            {
                plist.Mulf(stoi(second_ans[0]), stoi(second_ans[1]), stoi(second_ans[2]));
            }
        }
        else if (func == 3)
        {
            plist.printList();
        }
        else if (func == 0)
        {
            cout << "Program shutdown." << endl;
            break;
        }
        else
        {
            cout << "No such function, retry." << endl; 
        }
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