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
using namespace std;

Player::Player() {
    std::cout << "Inside default constructor of Player" << std::endl;
    this->_name="g";
    this->territoriesList=vector<Territory*>();
    this->orders=new OrderList();
    this->hand=new Hand();
}//default constructor

Player::Player(string _name){
    cout << "Inside parameterized constructor of Player" << endl;
    this->_name=_name;
    this->territoriesList=vector<Territory*>();
    this->orders=new OrderList();
    this->hand=new Hand();
}//1 parameter constructor

Player::Player(Hand* hand){
    cout << "Inside parameterized constructor of Player with hand" << endl;
    this->hand=new Hand(*(hand));
}//1 parameter constructor

Player::Player(const Player& p) {
    cout << "Inside copy constructor of Player" << endl;
    this->_name=p._name;
    this->orders=p.orders;
    this->hand=p.hand;
    this->territoriesList=p.territoriesList;
    for(int i=0;i<territoriesList.size();i++) {
        this->territoriesList.at(i) = p.territoriesList.at(i);
    }
}//copy constructor

Player& Player::operator=(const Player &p) {
    cout << "Inside operator  of Player" << endl;
    this->_name = p._name;
    this->territoriesList=p.territoriesList;
    this->orders=p.orders;
    this->hand=p.hand;
    return *this;
}//assignment op.
void Player::SetHand(Hand h) {


    cout << "Inside Set Hand" <<endl;

}

void Player::PrintToDefend() {
    int index =0;

    cout << "Printing  the territories to Defend " << endl;

    for (auto element: this->toDefend()) {

        cout << "This is Territory number " << index << " ,the type of this Territory is "   <<(*element) << " " << endl;
        index++;
    }
}

//Removes Player from the territory List
void Player::RemoveTerritory( Territory * t) {
cout << "We are removing a Territory" << endl;
    int count = 0;

    for (Territory *i: (this->territoriesList)) {

        if (t->number == i->number) {

            cout << "Removing territory  " << *t << endl;
            cout << "From the player " << *this << endl;
            territoriesList.erase(territoriesList.begin() + count);

        }
        count++;
    }
}
void Player::PrintToAttack() {
    int index =0;

    cout << "Printing  the territories to Attack " << endl;

    for (auto element: this->toAttack()) {

        cout << "This is Territory number " << index << " ,the type of this Territory is "   <<(*element) << " " << endl;
        index++;
    }
}
std::ostream &operator<<(std::ostream &stream, const Player &p) {
    stream << "Players" << p._name << "Territory" << endl;

    int index =1;
    cout << endl;
    cout<< "Printing the Territories" << endl;
    for (auto element: p.territoriesList) {

        stream << "This is Territory number " << index << " ,the type of this Territory is "   <<(*element) << " " << endl;
        index++;
    }
    index = 1;
    cout<< "Printing the Territories to Defend  " << endl;


    cout << endl;
    cout<< "Printing the Orders" << endl;

   // cout << p.orders->get_order_list_new().size()<<endl;

    //stream << *(p.orders) << endl;

    for (auto element: p.orders->get_order_list_new()) {

        stream << "This is Order number " << index << " ,the type of this Order is "   <<(*element) << " " << endl;
        index++;
    }

    index = 1;

    cout << endl;
    cout<< "Printing the Hands" << endl;
    for (auto element: p.hand->GetCollection()) {

        stream << "This is card number " << index << " ,the type of this card is "   <<(*element) << " " << endl;
        index++;
    }
    cout << endl;

    return stream;

}

Player::Player(vector<Territory*> territoriesList,OrderList* orders,Hand* hand, string _name ) {
    cout << "Here in Parameterized constructor of Player" << endl;
    //this->territoriesList = territoriesList;
    /*
    for (int i = 0; i < territoriesList.size(); i++) {
        territoriesList.at(i)->setPlayer(this);
    }
     */

    for (Territory* i: (territoriesList) ) {
       /*
        string name = i->name;
        int number = i->number;
        int numberOfArmies = i->numberOfArmies;
        int continentNumber = i->continentNumber;
        Territory *T1 = new Territory(name,number,numberOfArmies,continentNumber) ;
        */
        this->territoriesList.push_back(i);
    }

    vector<Order*> orderList=orders->get_order_list_new();

    vector<Order*> orderLists;

    cout << endl;
    cout<<orderLists.size()<<"TAGGG"<<endl;
    cout << endl;
    cout<< "Before Hand Constructor11" << endl;

    for (Order* i: (orderList) ){
        //string type = i->get_type();
        bool valid = i->get_valid();
        vector<string> vec_type1 = i->get_List();
        int type_id= i->get_ID();
        cout<<"Order this " << valid << endl;
        cout<<"Order this " <<type_id << endl;

        /*
        Order * T1 = new Order (valid,vec_type1,type_id);
        //this->getOrdersList()->get_order_list_new().push_back(T1);
        cout<< "Before Hand Constructor11223" << endl;
        // this->push_back(T1);
        orderLists.push_back(T1);
         */
        string type = i->type;
        //STOP1
        if(type == "Airlifts") {
            Order * T1 = new Airlifts (valid,vec_type1,type_id);
            orderLists.push_back(T1);
        }

        if(type == "Deploy") {
            Order * T1 = new Deploy (valid,vec_type1,type_id);
            orderLists.push_back(T1);
        }

        if(type == "Bombs") {
            Order * T1 = new Bombs (valid,vec_type1,type_id);
            orderLists.push_back(T1);
        }

        if(type == "Negotiate") {
            Order * T1 = new Negotiate (valid,vec_type1,type_id);
            orderLists.push_back(T1);
        }

        if(type == "Blockades") {
            Order * T1 = new Blockades (valid,vec_type1,type_id);
            orderLists.push_back(T1);
        }
    }
    cout << "The SIZE SPCIAL IS " <<  orderLists.size() << endl;
this->orders = new OrderList(orderLists);

cout << "After pUSHING bACK a Order pointer" << endl;
cout << *(this->orders) << endl;

this->_name=_name;
cout << "Before Hand Constructor" << endl;
this->hand= new Hand(*hand);
cout << "After Hand Constructor" << endl;
this->FillNeighboors();
}
void Player ::AddToList(Order *o) {

    this->orders->Add(o);
}
void Player::addTerritory(Territory *territory){
    territoriesList.push_back(territory);
    //territory->setPlayer(this);
}
vector<Territory*>Player::toAttack(){

    // Getting all the enemy Neighboors Territories
    vector<Territory *> array = this->Neighboors;

    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            //Order By least amount of armies to attack
            //Check swap Value
            if (array[j]->numberOfArmies > array[j+1]->numberOfArmies)
                swap((array[j]), array[j+1]);
        }
    }
    return array;;
}
vector<Territory*> Player::toDefend(){

   vector<Territory *> array = this->territoriesList;
    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            //Order By least amount of armies
            //Check swap Value
            if (array[j]->numberOfArmies > array[j+1]->numberOfArmies)
                swap((array[j]), array[j+1]);
        }
    }
    return array;
}
OrderList* Player::getOrdersList(){
    return orders;
}
Hand* Player::getHand(){
    return hand;
}
vector<Territory*> Player::getTerritoriesList(){
    return territoriesList;
}



vector<Territory *>  Player::BubbleSort (vector<Territory *> array){

    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            if (array[j]->numberOfArmies < array[j+1]->numberOfArmies)
                swap((array[j]), array[j+1]);
        }
    }
    return array;
}

void Player ::Setreinforcement_pool(int a) {
    this->reinforcement_pool = a;
}
vector<Territory *>  Player::BubbleSort2 (vector<Territory *> &array){

    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            if (array[j]->numberOfArmies > array[j+1]->numberOfArmies)
                swap((array[j]), array[j+1]);
        }
    }

    return array;
}

void  Player :: PrintNeighboors(){
    this->FillNeighboors ();

    int index =0;
    cout << endl;
    cout << endl;
    cout << "Printing  the Neighbors of All the territories acquired by this player" << endl;

    for (auto element: this->Neighboors) {

        cout << "This is Territory number " << index << " ,the type of this Territory is "   <<(*element) << " " << endl;
        index++;
    }

}

void Player ::FillNeighboors () {
// Neighboors ?
    bool found = true;
    for (Territory *t: this->territoriesList) {

        for (int i = 0; i < t->edges.size(); i++) {
            if(find(Neighboors.begin(),Neighboors.end(),  t->edges[i]) != Neighboors.end())
            {
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

void Player::IssueOrder(){

   /* Step 1 Decide the priority of the to Attack and to Defend methods
    In function of the number of armies in the Territory
    1-Loop through the vector of territories
    2- Sort the array by territory with the least number of armies
    3- The array in step 2 will become array of territories to defend
    4-Loop through the vector of territories again
    5-For each Territory,Store its neighbors in an array of territories
     std::vector<Territory*> edges; edges, is the neighbor for all the territories
    6-  Sort the array by territory with the least number of armies
    7-These are going to be the territories to attack
    */

   // 1-Loop through the vector of territories
   // 2-Sort the array by territory with the least number of armies
   // 3-The array in step 2 will become array of territories to defend

    vector<Territory *>  toDefend= this->BubbleSort(this->territoriesList);


    //4-Loop through the vector of territories again
   // 5-For each Territory,Store its neighbors in an array of territories
   // std::vector<Territory*> edges; edges, is the neighbor for all the territories
    //6-  Sort the array by territory with the least number of armies

//    vector<Territory *>  Neighboor = this->Neighboors(this->territoriesList);

   // vector<Territory *>  toAttack= this->BubbleSort2(Neighboor);
 //  Watchout for the pointers and references

   /*Step 2 -Deploy order
    * -Issue a deploy order in the list of armies to defend
    * -The list is coming from the to Defend mehtod
    * -As long as there are armies to deploy
    * -So we use to deploy and then as parameters pass the terrytories by priority
    * -We can implement a system of % , 50% for top 3 territories etc
    */

   for(Order * o : this->_OrderList){

    o->execute();

   };


    /* Step 3-Make a decision to attack or to defend
     *
     *Same as step 2 but to attack , what is the difference  ? ask Joey for that
     */

    /* Step-4 Once all of these have a done he can call a special order from the Hand
     *
     */

}