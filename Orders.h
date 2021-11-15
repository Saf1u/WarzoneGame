

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Cards.h"
#include "Orders.fwd.h"
#include "Player.fwd.h"
#include "Map.fwd.h"
#include "LoggingObserver.h"

using namespace std;

class Deck;

class Order : public ILoggable, public Subject {
public :
    Order();

    string LogMessage;

    Order(bool b, vector<string> vector1, int i);

    Order(Player *player, Map *map);

    ~Order();

    //copy constructor
    Order(const Order &O);

    //assignment construtor
    Order &operator=(const Order &O);

    friend std::ostream &operator<<(std::ostream &stream, const Order &e);

    //Pure virtual method to validate each order
    virtual bool validate() = 0;

    //Pure virtual method to execute each order
    virtual void execute() = 0;

    void SetPlayer(Player *player);

    void PrintAllOrder();

    void SetMap(Map *map);

    //set type of the subclass
    void set_type_id(int num);

    void setDeck(Deck *);

    void set_valid(bool valid);

    void set_vec_type1(vector<string> vec_type1);

    void SetListOfPlayers(vector<Player *>);

    string get_type();

    bool get_valid();

    vector<string> get_List();

    Territory *targetted_territory;

    int get_ID();

    Deck *deck;
    Player *p;
    //Add GameEngine Player
    Map *m;
    string type;

    vector<Player *> ListOfPlayers;
private :
    bool valid;
    vector<string> vec_type1 = {"Deploy", "Advance", "Bombs", "Blockades", "Airlifts", "Negotiate"};
    int type_id;
};

//subclass of order
class Deploy : public Order {

public:
    //constructor
    Deploy();

    //destructor
    ~Deploy();

    Deploy(bool valids, vector<string> vec_types1, int type_ids);

    Deploy(const Deploy &e);

    string stringToLog();


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

    string stringToLog();

    Advance(const Advance &e);

    Advance(bool valids, vector<string> vec_types1, int type_ids);

    Advance &operator=(const Advance &e);

    string type = {"Advance"};
private:

};

class Bombs : public Order {
public:
    Bombs();

    ~Bombs();

    string stringToLog();

    Bombs(bool valids, vector<string> vec_types1, int type_ids);

    Bombs(const Bombs &e);


    bool validate();

    void execute();

    Bombs &operator=(const Bombs &e);

    string type = {"Bomb"};
private:

};

class Blockades : public Order {
public:
    Blockades();

    ~Blockades();

    Blockades(const Blockades &e);


    bool validate();

    bool neutral = false;

    void execute();

    string stringToLog();

    Blockades(bool valids, vector<string> vec_types1, int type_ids);

    Blockades &operator=(const Blockades &e);

    string type = {"Blockade"};
private:

};

class Airlifts : public Order {
public:

    Airlifts();

    Airlifts(bool valids, vector<string> vec_types1, int type_ids);

    ~Airlifts();

    Airlifts(const Airlifts &e);

    bool validate();

    void execute();

    string stringToLog();

    Airlifts &operator=(const Airlifts &e);

    string type = {"Airlift"};
private:

};

class Negotiate : public Order {
public:
    Negotiate();

    ~Negotiate();

    Negotiate(bool valids, vector<string> vec_types1, int type_ids);

    Negotiate(const Negotiate &e);

    string stringToLog();


    bool validate();

    void execute();

    Negotiate &operator=(const Negotiate &e);

    string type = {"Negotiate"};
private:

};

class OrderList : public ILoggable, public Subject {
public:
    void set_order_list(Order *an_order);

    OrderList();

    OrderList(vector<Order *> e);

    OrderList &operator=(const OrderList &e);

    friend std::ostream &operator<<(std::ostream &stream, const OrderList &e);

    vector<Order *> *get_order_list();

    vector<Order *> get_order_list_new();

    string LogMessage;

    string stringToLog();

    void Add(Order *);

    //delete an order
    void remove(Order *oneOrder);

    //move
    void move(int position, int new_position);

private:
    vector<Order *> vec_order_list; //store the orders
};

//ATTACH THE OBSERVER!!!!!!!
