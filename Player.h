//
// Created by Noor on 2021-09-28.
//

#ifndef COMP345_PLAYER_H
#define COMP345_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include<Orders.h>
#include <Map.h>
#include <Cards.h>

using namespace std;

class Orders;
class Territory;
class Hand;

class Player{
public:
    //constructors
    Player();
    Player(string _name);

    Player(Hand * hand);

    Player(const Player& p);
    Player& operator=(const Player& p);
    friend std::ostream& operator <<(std::ostream& stream,const Player& p);
    Player(vector<Territory *> territoriesList, OrderList *orders, Hand *hand,string _name);

    vector <Territory*> territoriesList;
    vector<Order *>  _OrderList;
    //bool IssueOrder(String name);
    OrderList* orders;
    Hand* hand;


    void AddToList(Order* o);

    // void IssueOrder(Order o);
    Hand *getHand();
    void SetHand(Hand h);



    string _name;
    //METHODSS
    vector<Territory *> toAttack();
    void addTerritory(Territory *territory);
    vector<Territory *> toDefend();

    //MUTATORS AND ACCESSORS
    void setPlayer(Player *player);
    OrderList *getOrdersList();
    vector<Territory *> getTerritoriesList();

};


#endif //COMP345_PLAYER_H
