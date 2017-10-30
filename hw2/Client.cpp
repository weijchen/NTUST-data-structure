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
    // cout << "Destruct Client!" << endl;
}