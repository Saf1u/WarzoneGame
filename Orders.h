

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Cards.h"
#include "Orders.fwd.h"
#include "Player.fwd.h"
#include "Map.fwd.h"

using namespace std;

class Order {
public :
    Order();

    Order(bool b, vector<string> vector1, int i);
    Order(Player* player, Map * map);
    ~Order();
    Order(const Order& O);//copy constructor
    Order& operator = (const Order &O);//assignment construtor
    friend std::ostream& operator <<(std::ostream& stream, const Order& e);

    //check of the oder is valid
    virtual bool  validate() = 0;
    //execute method
    virtual void execute() = 0 ;

    //set type of the subclass
    void set_type_id(int num);

    void set_valid(bool valid);

    void set_vec_type1(vector<string> vec_type1 );

    string get_type();

    bool get_valid();

    vector<string> get_List();

    int get_ID();

    Player *p;
    Map *m;
    string  type;

private :
    bool valid;
    vector<string> vec_type1 = {"deploy", "advance", "Bombs", "Blockades", "Airlifts", "negotiate"};
    int type_id;
};

class Deploy : public Order {

public:
    Deploy();

    ~Deploy();

    Deploy(bool valids, vector<string> vec_types1 ,int type_ids );

    Deploy(const Deploy &e);


    bool validate();

    void execute();

    Deploy &operator=(const Deploy &e);

    string type = {"Deploy"};
private:
};

class Advance : public Order {
public:
    Advance();

    ~Advance();

    bool validate();

    void execute();

    Advance(const Advance &e);
    Advance(bool valids, vector<string> vec_types1 ,int type_ids );
    Advance &operator=(const Advance &e);

    string type = {"Advance"};
private:

};

class Bombs : public Order {
public:
    Bombs();

    ~Bombs();
    Bombs(bool valids, vector<string> vec_types1 ,int type_ids );
    Bombs(const Bombs &e);


    bool validate();

    void execute();

    Bombs &operator=(const Bombs &e);

    string type = {"Bombs"};
private:

};

class Blockades : public Order {
public:
    Blockades();

    ~Blockades();

    Blockades(const Blockades &e);


    bool validate();

    void execute();

    Blockades(bool valids, vector<string> vec_types1 ,int type_ids );

    Blockades &operator=(const Blockades &e);

    string type = {"Blockades"};
private:

};

class Airlifts : public Order {
public:

    Airlifts();

    Airlifts(bool valids, vector<string> vec_types1 ,int type_ids );

    ~Airlifts();

    Airlifts(const Airlifts &e);

    bool validate();

    void execute();

    Airlifts &operator=(const Airlifts &e);

    string type = {"Airlifts"};
private:

};

class Negotiate : public Order {
public:
    Negotiate();

    ~Negotiate();

    Negotiate(bool valids, vector<string> vec_types1 ,int type_ids );

    Negotiate(const Negotiate &e);


    bool validate();

    void execute();

    Negotiate &operator=(const Negotiate &e);

    string type = {"Negotiate"};
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


