//============================================================================
// Name        : pset2.cpp
// Author      : Jimmy
// Description : Stack and Queue for lineup question
//============================================================================
#include <iostream>
#include "Client.h"

#define MAX_CLIENT 10

using namespace std;

int main()
{
    // Initialize Variables
    Client* queue[MAX_CLIENT] = {};
    int cur_t = 0;
    int number = 0;
    int arrive_t, service_t, allowable_t;
    int depart_t = 0;
    int serve_check = 0;
    bool newClient = true;
    char ans_entclient, ans_begin;

    // enter clients' information
    while (newClient)
    {
        // not reach number limited
        if (number < MAX_CLIENT)
        {
            cout << "Enter Client " << number+1 << ":" << endl;
            cout << "Arrive time: " << flush;
            cin >> arrive_t;
            while (arrive_t < 0)
            {
                cout << "Arrive time can't be nagative!" << endl;
                cout << "Arrive time: " << flush;
                cin >> arrive_t;  
            }
            cout << "Service time: " << flush;
            cin >> service_t;
            while (service_t < 0)
            {
                cout << "Service time can't be nagative!" << endl;
                cout << "Service time: " << flush;
                cin >> service_t; 
            }
            cout << "Allowable waiting time: " << flush;
            cin >> allowable_t;
            while (allowable_t < 0)
            {
                cout << "Allowable wating time can't be nagative!" << endl;
                cout << "Allowable wating time: " << flush;
                cin >> allowable_t;  
            }
            queue[number] = new Client((number+1), arrive_t, service_t, allowable_t, serve_check, depart_t);
            
            // whether exist new client
            cout << "Enter Client? (Y/N) > " << flush;
            cin >> ans_entclient;
            if (ans_entclient == 'N' || ans_entclient == 'n')
            {
                newClient = false;
            }
            else
            {
                cout << endl;
                newClient = true;
                number++;
            } 
        }
        // reach number limited
        else
        {
            cout << "Reach client number limited!" << endl;
            cout << "Begin program? (Y/N) > " << flush;
            cin >> ans_begin;
            if (ans_begin != 'Y' && ans_begin != 'y')
            {
                return 0;
            }
            number--;
            newClient = false;
        }
    }

    // insert first client
    cur_t = queue[0]->get_arrive() + queue[0]->get_service();
    queue[0]->set_serve(1);
    queue[0]->set_depart(cur_t);

    // insert remaining clients
    // if two clients
    if (number == 1)
    {
        if (queue[1]->get_arrive() + queue[1]->get_allowable() > cur_t)
        {
            cur_t += queue[1]->get_service();
            queue[1]->set_serve(1);
            queue[1]->set_depart(cur_t);
        }
        // client arrives before prev finish unable to wait
        else
        {
            queue[1]->set_serve(0);
            queue[1]->set_depart(0); 
        }
    }
    // if more than two clients
    else
    {
        for (int i = 2; i <= number; i++)
        {
            // One client arrives before prev finish and the other not
            if (queue[i-1]->get_arrive() < cur_t && queue[i]->get_arrive() > cur_t)
            {
                // cout << "===== Case 1 =====" << endl;
                // client arrives before prev finish is available to wait
                if (queue[i-1]->get_arrive() + queue[i-1]->get_allowable() > cur_t)
                {
                    cur_t += queue[i-1]->get_service();
                    queue[i-1]->set_serve(1);
                    queue[i-1]->set_depart(cur_t);
                }
                // client arrives before prev finish unable to wait
                else
                {
                    queue[i-1]->set_serve(0);
                    queue[i-1]->set_depart(0); 
                }
            }
            // Both clients arrive before prev finish
            else if (queue[i-1]->get_arrive() < cur_t && queue[i]->get_arrive() < cur_t)
            {
                // cout << "===== Case 2 =====" << endl;
                if (queue[i-1]->get_arrive() + queue[i-1]->get_allowable() < cur_t)
                {
                    queue[i-1]->set_serve(0);
                    queue[i-1]->set_depart(0);
                }
                else
                {
                    if (queue[i]->get_arrive() + queue[i]->get_allowable() > cur_t)
                    {
                        // if second client can move a position forward
                        if (cur_t + queue[i]->get_service() < queue[i-1]->get_arrive() + queue[i-1]->get_allowable())
                        {
                            Client *temp = queue[i];
                            queue[i] = queue[i-1];
                            queue[i-1] = temp;
                        }
                        cur_t += queue[i-1]->get_service();
                        queue[i-1]->set_serve(1);
                        queue[i-1]->set_depart(cur_t);  
                    }
                    else
                    {
                        if (queue[i-1]->get_arrive() + queue[i-1]->get_allowable() > cur_t)
                        {
                            cur_t += queue[i-1]->get_service();
                            queue[i-1]->set_serve(1);
                            queue[i-1]->set_depart(cur_t);
                        }
                        else
                        {
                            queue[i-1]->set_serve(0);
                            queue[i-1]->set_depart(0); 
                        }
                    }
                }
            }
            else if (queue[i-1]->get_arrive() > cur_t && queue[i]->get_arrive() > cur_t)
            {
                // cout << "===== Case 3 =====" << endl;
                // if second client can move a position forward
                if (cur_t + queue[i]->get_service() < queue[i-1]->get_arrive() + queue[i-1]->get_allowable())
                {
                    Client *temp = queue[i];
                    queue[i] = queue[i-1];
                    queue[i-1] = temp;
                }
                cur_t += queue[i-1]->get_service();
                queue[i-1]->set_serve(1);
                queue[i-1]->set_depart(cur_t);
            } 
        }
        
        // Check last client
        if (queue[number]->get_arrive() + queue[number]->get_allowable() > cur_t)
        {
            cur_t += queue[number]->get_service();
            queue[number]->set_serve(1);
            queue[number]->set_depart(cur_t);
        }
        else
        {
            queue[number]->set_serve(0);
            queue[number]->set_depart(0); 
        }
    }


    // Sort id
    for (int i = 1; i <= number; i++)
    {
        if (queue[i]->id() < queue[i-1]->id())
        {
            Client *temp = queue[i];
            queue[i] = queue[i-1];
            queue[i-1] = temp;
        }
    }

    // Display final results
    cout << "===== Final results =====" << endl;
    cout << "\t\tServed or not?\tDeparture time" << endl;
    for (int i = 0; i <= number; i++)
    {
        cout << "Client " << queue[i]->id() << ":\t" << flush;
        if (queue[i]->get_serve() == 1)
        {
            cout << "    Yes\t\t     " << flush;
            cout << queue[i]->get_depart() << endl;
        }
        else
        {
            cout << "    No" << endl;
        }
    }

    // Destructor 
    // cout << "===== Destructor =====" << endl;
    for (int i = 0; i <= number; i++)
    {
        delete queue[i];
    }
    return 0;
}