//============================================================================
// Name        : pset4.cpp
// Author      : Jimmy
// Description : BST-minelement
//============================================================================
#include <iostream>
#include "BST.h"

int main()
{
    BST obj;
    char option;
    obj.load_f();

    bool enter = true;
    while(enter)
    {
        string input;
        cout << "Enter node, Q to quit > ";
        getline(cin, input);
        if (input == "Q" || input == "q")
        {
            enter = false;
        }
        else
        {
            int val = stoi(input);
            obj.access(val);
        }
    }

    while(1)
    {
        puts("********************");
        puts("1. Insert");
        puts("2. Delete");
        puts("3. Show");
        puts("4. Minelement");
        puts("5. Root val");
        puts("6. Quit");
        puts("********************");
        cout << "Enter your choice: ";
        option = getchar();
        while (getchar() != '\n') continue;
        cout << "\n";
        switch(option)
        {
            case '1':
                obj.insert_f();
                puts("");
                break;
            case '2':
                obj.delete_f();
                puts("");
                break;
            case '3':
                obj.show_f();
                puts("");
                break;
            case '4':
                obj.minelement_f();
                puts("");
                break;
            case '5':
                obj.root_f();
                puts("");
                break;
            case '6':
                exit(0);

            default:
                puts("Wrong option!");
        }
    }
    system("pause");
    return 0;
}