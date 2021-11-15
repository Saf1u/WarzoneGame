//
// Created by Noor on 2021-09-28.
//

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "Cards.h"
#include "GameEngine.h"
#include "Orders.fwd.h"
#include "Player.fwd.h"
#include <algorithm>

class GameEngine;

using namespace std;

class Hand;

class Player {
public:
    //constructors
    Player();

    Player(string _name);

    Player(Hand *hand);

    int ghostDeploys;

    Player(const Player &p);

    Player &operator=(const Player &p);

    friend std::ostream &operator<<(std::ostream &stream, const Player &p);

    Player(vector<Territory *> territoriesList, OrderList *orders, Hand *hand, string _name);

    //List for territories
    vector<Territory *> territoriesList;
    //list for orders
    vector<Order *> _OrderList;

    string GetName();

    OrderList *orders;
    Hand *hand;

    void AddToList(Order *o);

    bool negotiate = false;
    Player *enemynottoattack;

    void setNegotiate(Player *);

    int reinforcement_pool;

    void Setreinforcement_pool(int);

    void RemoveTerritory(Territory *t);

    void PrintToDefend();

    void PrintToAttack();

    void PrintNeighboors();

    void IssueOrder();

    Hand *getHand();

    void SetHand(Hand h);

    GameEngine *Game;
    bool FinishedIssueOrder = false;

    void SetGameEngine(GameEngine *game);

    vector<Territory *> BubbleSort(vector<Territory *> array);

    //Call it at the of each turn
    void FillNeighboors();

    void SetID(int ID);

    vector<Territory *> BubbleSort2(vector<Territory *> &array);

    string _name;

    //METHODSS
    vector<Territory *> toAttack();

    void addTerritory(Territory *territory);

    vector<Territory *> toDefend();

    vector<Territory *> Neighboors;

    //MUTATORS AND ACCESSORS
    void setPlayer(Player *player);

    OrderList *getOrdersList();

    vector<Territory *> getTerritoriesList();

    // has to be unique to each player
    int id;
};




