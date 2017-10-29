// Client.cpp
#include <iostream>
#include "Client.h"

using namespace std;

Client::Client(int id, int arrive, int service, int allowable, int serve, int depart) : id_(id), arrive_(arrive), service_(service), allowable_(allowable), serve_(serve), depart_(depart)
{} // empty

int Client::id()
{
    return id_;
}
int Client::get_arrive()
{
    return arrive_;
}
int Client::get_service()
{
    return service_;
}
int Client::get_allowable()
{
    return allowable_;
}
int Client::get_serve()
{
    return serve_;
}
int Client::get_depart()
{
    return depart_;
}
void Client::set_arrive(int arrive)
{
    arrive_ = arrive;
}
void Client::set_serivce(int service)
{
    service_ = service;
}
void Client::set_allowable(int allowable)
{
    allowable_ = allowable;
}
void Client::set_serve(int serve)
{
    serve_ = serve;
}
void Client::set_depart(int depart)
{
    depart_ = depart;
}
Client::~Client()
{
    cout << "Destruct Client!" << endl;
}
// bool Client::IsEmpty()
// {
//     if(front > rear)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// bool Client::IsFull()
// {
//     if(this->size() >= MAX_SIZE)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// void Client::enClient(int data)
// {
//     // arriving time, service time, allowable wating time
//     item[++rear] = data;
//     // int arrive, service, allowable;
//     // cout << "Arrive time: >" << flush;
//     // cin >> arrive;
//     // cout << "Service time: >" << flush;
//     // cin >> service;
//     // cout << "Allowable time: >" << flush;
//     // cin >> allowable;
//     // item[++rear] = new ThreeTimeNode(arrive, service, allowable);
// }
// int Client::deClient()
// {
//     return item[front++];
// }
// void Client::display()
// {
//     if(!this->IsEmpty())
//     {
//         for(int i = front; i <= rear; i++)
//             cout << item[i] << endl;
//     }
//     else
//     {
//         cout << "Client Underflow" << endl;
//     }
// }
// int Client::size()
// {
//     return (rear - front + 1);
// }

// // T& Client::Front() const
// // {

// // }
// // T& Client::Rear() const
// // {

// // }