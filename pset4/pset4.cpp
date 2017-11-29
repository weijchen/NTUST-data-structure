//============================================================================
// Name        : pset4.cpp
// Author      : Jimmy
// Description : BST
//============================================================================
#include <iostream>
#include "BST.h"

int main()
{
    BST obj;
    char option;
    obj.load_f();
    while(1)
    {
        puts("********************");
        puts("1. Insert");
        puts("2. Delete");
        puts("3. Minelement");
        puts("4. Show");
        puts("5. Quit");
        puts("6. Root val");
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
                obj.minelement_f();
                puts("");
                break;
            case '4':
                obj.show_f();
                puts("");
                break;
            case '5':
                exit(0);
            case '6':
                obj.root_f();
                puts("");
                break;
            default:
                puts("Wrong option!");
        }
    }
    system("pause");
    return 0;
}