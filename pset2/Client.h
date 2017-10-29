// Client.h
#ifndef CLIENT_H_
#define CLIENT_H_

using namespace std;

class Client
{
private:
    int id_, arrive_, service_, allowable_, serve_, depart_;

public:
    Client(int id, int arrive, int service, int allowable, int serve, int depart);
    int id();

    int get_arrive();
    int get_service();
    int get_allowable();
    int get_serve();
    int get_depart();

    void set_arrive(int arrive);
    void set_serivce(int service);
    void set_allowable(int allowable);
    void set_serve(int serve);
    void set_depart(int depart);

    ~Client(void);
};


    // bool IsEmpty();
    // bool IsFull();
    // // T& Front() const;
    // // T& Rear() const;
    // void enqueue(int);<std::array<int, N> >
    // // void enqueue(const T& item);
    // int dequeue();
    // int size();
    // void display();

#endif /* CLIENT_H_ */