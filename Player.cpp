//
// Created by Noor on 2021-09-28.
//

#include "Player.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include "Orders.h"
#include <set>
#include "Cards.h"
#include <algorithm>
#include "GameEngine.h"

using namespace std;

Player::Player() {

    this->_name = "g";
    this->territoriesList = vector<Territory *>();
    this->orders = new OrderList();
    this->hand = new Hand();
}//default constructor
// setting strategies for different players
void Player::SetStrategy(PlayerStrategies *p) {
    ps = p;
    string strategy = p->name;
    if (strategy == "HumanPlayer") {
        this->humanPlay = true;
        this->CheaterPlayer = false;
        this->AgressivePlayer = false;
        this->NeutralPlayer = false;
    }
    if (strategy == "CheaterPlayer") {
        this->humanPlay = false;
        this->CheaterPlayer = true;
        this->AgressivePlayer = false;
        this->NeutralPlayer = false;
    }

    if (strategy == "BenevolentPlayer") {

    }
    if (strategy == "AggressivePlayer") {
        this->humanPlay = false;
        this->CheaterPlayer = false;
        this->AgressivePlayer = true;
        this->NeutralPlayer = false;
    }
    if (strategy == "NeutralPlayer") {
        this->humanPlay = false;
        this->CheaterPlayer = false;
        this->AgressivePlayer = false;
        this->NeutralPlayer = true;
    }

}

Player::Player(string _name) {

    this->_name = _name;
    this->territoriesList = vector<Territory *>();
    this->orders = new OrderList();
    this->hand = new Hand();
}//1 parameter constructor

Player::Player(Hand *hand) {

    this->hand = new Hand(*(hand));
}//1 parameter constructor

Player::Player(const Player &p) {

    this->_name = p._name;
    this->orders = p.orders;
    this->hand = p.hand;
    this->territoriesList = p.territoriesList;
    for (int i = 0; i < territoriesList.size(); i++) {
        this->territoriesList.at(i) = p.territoriesList.at(i);
    }
}//copy constructor

Player &Player::operator=(const Player &p) {

    this->_name = p._name;
    this->territoriesList = p.territoriesList;
    this->orders = p.orders;
    this->hand = p.hand;
    return *this;
}//assignment op.
void Player::SetHand(Hand h) {


}

void Player::PrintToDefend() {
    int index = 0;
    cout << "Printing  the territories to Defend " << endl;

    for (auto element: this->toDefend()) {

        cout << "This is Territory number " << index << " ,the type of this Territory is " << (*element) << " " << endl;
        index++;
    }
}

//Removes Player from the territory List
void Player::RemoveTerritory(Territory *t) {
    cout << "We are removing a Territory" << endl;
    int count = 0;

    for (Territory *i: (this->territoriesList)) {

        if (t->number == i->number) {

            cout << "Removing territory  " << *t << endl;
            cout << "Removing territory From the player " << this->_name << endl;
            territoriesList.erase(territoriesList.begin() + count);

        }
        count++;
    }
}

void Player::PrintToAttack() {
    int index = 0;
    cout << "Printing  the territories to Attack " << endl;
    for (auto element: this->toAttack()) {
        cout << "This is Territory number " << index << " ,the type of this Territory is " << (*element) << " " << endl;
        index++;
    }
}

std::ostream &operator<<(std::ostream &stream, const Player &p) {
    stream << "Players" << p._name << "Territory" << endl;

    int index = 1;
    cout << endl;
    cout << "Printing the Territories" << endl;
    for (auto element: p.territoriesList) {

        stream << "This is Territory number " << index << " ,the type of this Territory is " << (*element) << " "
               << endl;
        index++;
    }
    index = 1;
    cout << "Printing the Territories to Defend  " << endl;

    cout << endl;
    cout << "Printing the Orders" << endl;

    for (auto element: p.orders->get_order_list_new()) {

        stream << "This is Order number " << index << " ,the type of this Order is " << (*element) << " " << endl;
        index++;
    }

    index = 1;

    cout << endl;
    cout << "Printing the Hands" << endl;
    for (auto element: p.hand->GetCollection()) {

        stream << "This is card number " << index << " ,the type of this card is " << (*element) << " " << endl;
        index++;
    }
    cout << endl;

    return stream;

}

Player::Player(vector<Territory *> territoriesList, OrderList *orders, Hand *hand, string _name) {
    cout << "Here in Parameterized constructor of Player" << endl;

    for (Territory *i: (territoriesList)) {
        this->territoriesList.push_back(i);
    }

    vector<Order *> orderList = orders->get_order_list_new();

    vector<Order *> orderLists;

    cout << endl;
    cout << orderLists.size() << "TAGGG" << endl;
    cout << endl;
    cout << "Before Hand Constructor11" << endl;

    for (Order *i: (orderList)) {
        bool valid = i->get_valid();
        vector<string> vec_type1 = i->get_List();
        int type_id = i->get_ID();
        cout << "Order this " << valid << endl;
        cout << "Order this " << type_id << endl;
        string type = i->type;
        //STOP1
        if (type == "Airlifts") {
            Order *T1 = new Airlifts(valid, vec_type1, type_id);
            orderLists.push_back(T1);
        }

        if (type == "Deploy") {
            Order *T1 = new Deploy(valid, vec_type1, type_id);
            orderLists.push_back(T1);
        }

        if (type == "Bombs") {
            Order *T1 = new Bombs(valid, vec_type1, type_id);
            orderLists.push_back(T1);
        }

        if (type == "Negotiate") {
            Order *T1 = new Negotiate(valid, vec_type1, type_id);
            orderLists.push_back(T1);
        }

        if (type == "Blockades") {
            Order *T1 = new Blockades(valid, vec_type1, type_id);
            orderLists.push_back(T1);
        }
    }
    cout << "The SIZE SPCIAL IS " << orderLists.size() << endl;
    this->orders = new OrderList(orderLists);

    cout << "After pUSHING bACK a Order pointer" << endl;
    cout << *(this->orders) << endl;

    this->_name = _name;
    cout << "Before Hand Constructor" << endl;
    this->hand = new Hand(*hand);
    cout << "After Hand Constructor" << endl;
    this->FillNeighboors();
}

void Player::AddToList(Order *o) {

    this->orders->Add(o);
}

void Player::addTerritory(Territory *territory) {
    territoriesList.push_back(territory);
}

vector<Territory *> Player::toAttack() {
    return ps->toAttack();
}

vector<Territory *> Player::toDefend() {
    return ps->toDefend();
}

OrderList *Player::getOrdersList() {
    return orders;
}

Hand *Player::getHand() {
    return hand;
}

vector<Territory *> Player::getTerritoriesList() {
    return territoriesList;
}


vector<Territory *> Player::BubbleSort(vector<Territory *> array) {

    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++) {
        //compare elemet to the next element, and swap if condition is true
        for (int j = 0; j < array.size() - 1; j++) {
            if (array[j]->numberOfArmies < array[j + 1]->numberOfArmies)
                swap((array[j]), array[j + 1]);
        }
    }
    return array;
}

void Player::Setreinforcement_pool(int a) {
    this->reinforcement_pool = a;
    this->Game->gameReinforcementPool -= a;
}

vector<Territory *> Player::BubbleSort2(vector<Territory *> &array) {

    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++) {
        //compare elemet to the next element, and swap if condition is true
        for (int j = 0; j < array.size() - 1; j++) {
            if (array[j]->numberOfArmies > array[j + 1]->numberOfArmies)
                swap((array[j]), array[j + 1]);
        }
    }

    return array;
}

Player::~Player() {
    Game = nullptr;
    vector<Order *> ordersToDelete = orders->get_order_list_new();
    for (int i = 0; i < ordersToDelete.size(); i++) {
        delete ordersToDelete[i];
    }
}

void GameEngine::RemovePlayer(Player *p) {

    int index = 0;
    for (Player *c: this->players) {

        if (c->ps->name == p->ps->name) {
            this->players.erase(this->players.begin() + index);
        }
        index++;
    }
}

void Player::PrintNeighboors() {
    this->FillNeighboors();

    int index = 0;
    cout << endl;
    cout << endl;
    cout << "Printing  the Neighbors of All the territories acquired by this player" << endl;

    for (auto element: this->Neighboors) {

        cout << "This is Territory number " << index << " ,the type of this Territory is " << (*element) << " " << endl;
        index++;
    }

}

void Player::FillNeighboors() {
    bool found = true;
    for (Territory *t: this->territoriesList) {

        for (int i = 0; i < t->edges.size(); i++) {
            if (find(Neighboors.begin(), Neighboors.end(), t->edges[i]) != Neighboors.end()) {
                cout << "Element found";
                found = false;
            } else {
                cout << "Adding new Neighbor Territory" << endl;
                cout << "Yes" << endl;
                this->Neighboors.push_back(t->edges[i]);
            }
        }
    }
}

void Player::SetGameEngine(GameEngine *game) {

    this->Game = game;
};

void Player::IssueOrder() {
    FillNeighboors();
    ps->issueOrder();
}

string Player::GetName() {
    return _name;
}

void Player::setNegotiate(Player *pt) {
    this->negotiate = true;
    this->enemynottoattack = pt;
}

void Player::SetID(int ID) {

    this->id = ID;
}
