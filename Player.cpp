//
// Created by Noor on 2021-09-28.
//

#include "Player.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <Orders.h>
#include <set>
#include <Cards.h>
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
    this->territoriesList = territoriesList;
    /*
    for (int i = 0; i < territoriesList.size(); i++) {
        territoriesList.at(i)->setPlayer(this);
    }
     */
    for (Territory* i: (territoriesList) ) {
        string name = i->name;
        int number = i->number;
        int numberOfArmies = i->numberOfArmies;
        int continentNumber = i->continentNumber;
        Territory *T1 = new Territory(name,number,numberOfArmies,continentNumber) ;
        this->territoriesList.push_back(T1);
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

        Order * T1 = new Order (valid,vec_type1,type_id);

        //this->getOrdersList()->get_order_list_new().push_back(T1);
        cout<< "Before Hand Constructor11223" << endl;
        // this->push_back(T1);
        orderLists.push_back(T1);
    }
    cout << "The SIZE SPCIAL IS " <<  orderLists.size() << endl;
this->orders = new OrderList(orderLists);

cout << "After pUSHING bACK a Order pointer" << endl;
cout << *(this->orders) << endl;

this->_name=_name;
cout << "Before Hand Constructor" << endl;
this->hand= new Hand(*hand);
cout << "After Hand Constructor" << endl;
}
void Player ::AddToList(Order *o) {

    this->orders->Add(o);
}
void Player::addTerritory(Territory *territory){
    territoriesList.push_back(territory);
    //territory->setPlayer(this);
}
vector<Territory*>Player::toAttack(){
    vector<Territory*>territories_to_attack;
    territories_to_attack.push_back(new Territory("test",9,9,5));
    return territories_to_attack;
}
vector<Territory*>Player::toDefend(){
    vector<Territory*>territories_to_defend;
    territories_to_defend.push_back(new Territory("test",9,9,5));
    return territories_to_defend;
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

/*
bool Player::IssueOrder(String name){
    Order *order_ptr=new Order("Advance!!!","Advance onto this place");
    orderList->add(order_ptr);
    return true;

}
*/