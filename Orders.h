

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Order {
public :
    Order();

    Order(bool b, vector<string> vector1, int i);

    ~Order();
    Order(const Order& O);//copy constructor
    Order& operator = (const Order &O);//assignment construtor
    friend std::ostream& operator <<(std::ostream& stream, const Order& e);


    //check of the oder is valid
    virtual void validate() = 0;
    //execute method
    virtual void execute() = 0;

    //set type of the subclass
    void set_type_id(int num);

    string get_type();

    bool get_valid();

    vector<string> get_List();

    int get_ID();

private :
    bool valid;
    vector<string> vec_type1 = {"deploy", "advance", "Bombs", "Blockades", "Airlifts", "negotiate"};
    int type_id;
};

class Deploy : public Order {

public:
    Deploy();

    ~Deploy();

    Deploy(const Deploy &e);

    Deploy &operator=(const Deploy &e);

    string *get_type();

private:
    string type1 = {"deploy"};
};

class Advance : public Order {
public:
    Advance();

    ~Advance();

    Advance(const Advance &e);

    Advance &operator=(const Advance &e);

private:
};

class Bombs : public Order {
public:
    Bombs();

    ~Bombs();

    Bombs(const Bombs &e);

    Bombs &operator=(const Bombs &e);

private:
};

class Blockades : public Order {
public:
    Blockades();

    ~Blockades();

    Blockades(const Blockades &e);

    Blockades &operator=(const Blockades &e);

private:
};

class Airlifts : public Order {
public:
    Airlifts();

    ~Airlifts();

    Airlifts(const Airlifts &e);

    Airlifts &operator=(const Airlifts &e);

private:
};

class Negotiate : public Order {
public:
    Negotiate();

    ~Negotiate();

    Negotiate(const Negotiate &e);

    Negotiate &operator=(const Negotiate &e);

private:
};

class OrderList {
public:
    void set_order_list(Order *an_order);
    OrderList( );
    OrderList( vector<Order *> e);

    OrderList& operator =(const OrderList& e);

    friend std::ostream& operator <<(std::ostream& stream, const OrderList& e);
    vector<Order *> *get_order_list();
    vector<Order *>  get_order_list_new();

    void Add(Order *);
    //delete an order
    void remove(Order *oneOrder);

    //move
    void move(int position, int new_position);

private:
    vector<Order *> vec_order_list; //store the orders
};


