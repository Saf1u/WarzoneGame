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

// constructors for player class
Player::Player() {
    std::cout << "Inside default constructor of Player" << std::endl;
    this->_name = "g";
    this->territoriesList = vector<Territory *>();
    this->orders = new OrderList();
    this->hand = new Hand();
}//default constructor

Player::Player(string _name) {
    cout << "Inside parameterized constructor of Player" << endl;
    this->_name = _name;
    this->territoriesList = vector<Territory *>();
    this->orders = new OrderList();
    this->hand = new Hand();
}//1 parameter constructor

Player::Player(Hand *hand) {
    cout << "Inside parameterized constructor of Player with hand" << endl;
    this->hand = new Hand(*(hand));
}//1 parameter constructor

Player::Player(const Player &p) {
    cout << "Inside copy constructor of Player" << endl;
    this->_name = p._name;
    this->orders = p.orders;
    this->hand = p.hand;
    this->territoriesList = p.territoriesList;
    for (int i = 0; i < territoriesList.size(); i++) {
        this->territoriesList.at(i) = p.territoriesList.at(i);
    }
}//copy constructor

Player &Player::operator=(const Player &p) {
    cout << "Inside operator  of Player" << endl;
    this->_name = p._name;
    this->territoriesList = p.territoriesList;
    this->orders = p.orders;
    this->hand = p.hand;
    return *this;
}//assignment op.
void Player::SetHand(Hand h) {


    cout << "Inside Set Hand" << endl;

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
        //string type = i->get_type();
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

    // Getting all the enemy Neighboors Territories
    vector<Territory *> array = this->Neighboors;

    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++) {
        //compare elemet to the next element, and swap if condition is true
        for (int j = 0; j < array.size() - 1; j++) {
            //Order By least amount of armies to attack
            //Check swap Value
            if (array[j]->numberOfArmies > array[j + 1]->numberOfArmies)
                swap((array[j]), array[j + 1]);
        }
    }
    return array;;
}

vector<Territory *> Player::toDefend() {

    vector<Territory *> array = this->territoriesList;
    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++) {
        //compare elemet to the next element, and swap if condition is true
        for (int j = 0; j < array.size() - 1; j++) {
            //Order By least amount of armies
            //Check swap Value
            if (array[j]->numberOfArmies > array[j + 1]->numberOfArmies)
                swap((array[j]), array[j + 1]);
        }
    }
    return array;
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
        //compare element to the next element, and swap if condition is true
        for (int j = 0; j < array.size() - 1; j++) {
            if (array[j]->numberOfArmies > array[j + 1]->numberOfArmies)
                swap((array[j]), array[j + 1]);
        }
    }

    return array;
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
// Neighboors ?
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


    bool CanAdvance = false;
    bool SpecialOrder = false;

    this->FillNeighboors();

    //Returns list of enemy territories that are neighbors that we can attack
    toAttack();

    //Returns list of  territories that belong to the player that we can defend
    toDefend();
    //player ghostDeploys=10
    bool deployExist = false;
    bool advanceExist = false;
    for (auto o: this->orders->get_order_list_new()) {
        if (o->get_type() == "Deploy") {
            deployExist = true;
        }
        if (o->get_type() == "Advance") {
            advanceExist = true;
        }
    }

    //Check for dpeloy
    if (!deployExist) {
        Deploy *d = new Deploy;
        d->p = this;
        d->ListOfPlayers = this->Game->players;
        d->m = this->Game->map;
        d->deck = this->Game->gameDeck;

        d->Attach(Game->o);
        this->orders->Add(d);
        deployExist = true;
    }




    //Check for Advance
    if (!advanceExist) {
        bool AdvanceAttack = true;
        if (this->toAttack().size() == 0)
            AdvanceAttack = false;

        bool AdvanceDeploy = true;
        if (this->toDefend().size() == 0)
            AdvanceDeploy = false;

        if (AdvanceAttack || AdvanceDeploy) {
            Advance *d = new Advance;
            d->p = this;
            d->ListOfPlayers = this->Game->players;
            d->deck = this->Game->gameDeck;
            d->Attach(Game->o);
            d->m = this->Game->map;
            this->orders->Add(d);
            CanAdvance = true;
        }
    }


    //Verify for the Execution of a Special Order

    vector<Card *> Hand = this->getHand()->GetCollection();
//Monitor if we have already pushed a  Card

//Play will remove the Card from the player Hand
    string CardType;
    if (Hand.size() != 0) {
        for (Card *c: Hand) {

            CardType = c->GetType();

            if (CardType == "Bomb") {
                //Plays the Card
                c->play(CardType, this);
                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Airlift") {
                c->play(CardType, this);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Diplomacy") {
                c->play(CardType, this);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Blockade") {
                c->play(CardType, this);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }
            if (CardType == "Reinforcement") {
                c->play(CardType, this);
                // This breaks out of the loop so we can push one Card at a time
                break;
            }


        }
    } else {
        cout << "We have Used all the cards inside the player's hand" << endl;
        SpecialOrder = true;
    }
    if (this->_name == "Neutral" && (territoriesList.size() == 0 || advanceExist) &&
        hand->GetCollection().size() == 0) {
        this->FinishedIssueOrder = true;
    }
    if (advanceExist && SpecialOrder && deployExist) {
        this->FinishedIssueOrder = true;
        return;
    }
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
