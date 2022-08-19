
/**
 *  Done by Maamar Koudri
 * Student ID : 40057671
 * Class : Comp-345
 */

#include<iostream>
#include "Cards.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>  /* srand, rand */
#include <time.h>
#include <cstdlib>
#include <ctime>
#include "GameEngine.h"
using namespace std;

// Ancestor class Card
/**
 * Copy constructor of the Ancestor class Card
 */
 Card::Card(){

}
/**
 * Destructor of the Ancestor class Card
 */
Card::~Card() {

}
/**
 * Parameterized constructor of the Ancestor class
 */
Card::Card(string type) : _type(type){

    this->_type = type;
}
/**
 * copy constructor of the Ancestor class
 */
Card::Card(const Card& e){

    this->_type = e._type;
}
/**
 * assignment operator of the Ancestor class
 */
Card& Card::operator=(const Card& e){

    this->_type = (e._type);
    return *this;
}
/**
 * stream operator of the Ancestor class
 */
std::ostream& operator<<(std::ostream& stream, const Card& e){



    return stream << "Card details, type: " << (e._type) << endl;
}

void Card::SetDeck( Deck * deck){
    this->deck = deck;
}

void Card::SetPlayer( Player * p){
    this->p=p;
}

/**
 * The play method that would issue an order , put in the player list of orders and remove the card from the hand
 */
void Card::play(string type,Player* playerA) {


     //PlayCome
     //Creates an order Object and place it in the player list
    if(type == "Airlift") {

        Order * T1 = new Airlifts;

        T1->SetPlayer(playerA);
        T1->setDeck(playerA->Game->gameDeck);

        T1->SetListOfPlayers(playerA->Game->players);
        T1->SetMap(playerA->Game->map);
        T1->Attach(playerA->Game->o);
        playerA->orders->Add(T1);
    }
    if(type == "Bomb") {

        Order * T1 = new Bombs;
        T1->SetPlayer(playerA);
        T1->setDeck(playerA->Game->gameDeck);

        T1->SetListOfPlayers(playerA->Game->players);
        T1->SetMap(playerA->Game->map);
        T1->Attach(playerA->Game->o);
        playerA->orders->Add(T1);
    }
    if(type == "Blockade") {

        Order * T1 = new Blockades;
        T1->SetPlayer(playerA);
        T1->setDeck(playerA->Game->gameDeck);

        T1->SetListOfPlayers(playerA->Game->players);
        T1->SetMap(playerA->Game->map);
        T1->Attach(playerA->Game->o);
        playerA->orders->Add(T1);
    }

    if(type == "Reinforcement") {

        //Activate it here
        int armies = 5;
        int PlayerArmies = playerA->reinforcement_pool;
        playerA->reinforcement_pool = armies + PlayerArmies;

    }


    if(type == "Diplomacy") {
//Negotiate orderd
        Order * T1 = new Negotiate;
        T1->SetPlayer(playerA);
        T1->setDeck(playerA->Game->gameDeck);

        T1->SetListOfPlayers(playerA->Game->players);
        T1->SetMap(playerA->Game->map);
        T1->Attach(playerA->Game->o);
        playerA->orders->Add(T1);
    }

     //3Removes the card from the hand and places it in the Deck
     //this is pointer

    playerA->getHand()->remove(this);
    //Removing the card from the Deck
    this->deck->Add(this);
    // Return the card to the Deck


}

/**
 * This is the print method for the Ancesstor class
 */
 void Card::print() const {

    cout << "The type of this card is : " <<_type << endl;
 }

 /**
  * Returns the type of this
  * @return
  */
string Card::GetType() {
    return _type;
}

/**
 * This is the bomb  default constructor
 */
Bomb::Bomb() : Card(){



}

/**
 * This is the default constructor
 */
Bomb::~Bomb()  {

}

/**
 * This is the parameter constructor
 */
 Bomb::Bomb(string  type) : Card(type), _type(type){

     this->_type = type;

 }

/**
* This is the bomb get type method
*/
string Bomb::GetType() {
     return this->_type;
 }

 /**
  * This is the copy Constructor of bomb card
  * @parame
  */
Bomb::Bomb(const Bomb& e) :Card(e){

    this->_type =e._type;
}

/**
 * Inside the operator of Bomb Card
 * @parame
 * @return
 */
Bomb& Bomb::operator=(const Bomb& e){


    Card::operator=(e);
    this->_type =e._type;
    return *this;
}
/**
 * Inside the stream operator of bomb card
 * @param
 * @param
 * @return
 */
std::ostream& operator<<(std::ostream& stream, const Bomb& e){



    return stream << "Card details, type:" << e._type << endl;
}

/**
 * The bomb play method that will call its ancestor class
 * @param x
 * @return
 */
Card* Bomb::play(Player x) {
  return this->play(x);
}

/**
 * The bomb print method
 */
void Bomb::print() const {

    cout << "The type of this card is Bomb: " <<this->_type << endl;
}

/**
 * Default Constructor of Reinforcement Card
 */
Reinforcement::Reinforcement() : Card(){




}
/**
 * Inside the Reinforcement Card destructor
 */
Reinforcement::~Reinforcement() {

}
/**
 * arameter constructor of Reinforcement Card
 * @param type
 */
Reinforcement::Reinforcement(string  type) : Card(type), _type(type){

    this->_type = type;
}
/**
 * Inside copy constructor of  Reinforcement Card
 * @param e
 */
Reinforcement::Reinforcement(const Reinforcement& e) :Card(e){

    this->_type = e._type;
}
/**
 * Returns the type of this Reinforcement card
 * @return
 */
string Reinforcement::GetType() {
    return this->_type;
}
/**
 * Inside the operator of Reinforcement Card
 * @param e
 * @return
 */
Reinforcement& Reinforcement::operator=(const Reinforcement& e){

    Card::operator=(e);
    this->_type = e._type;
    return *this;
}
/**
 * Inside the stream operator of Reinforcement
 * @param stream
 * @param e
 * @return
 */
std::ostream& operator<<(std::ostream& stream, const Reinforcement& e){



    return stream << "Card details, type: " << e._type << endl;
}

/**
 * Reinforcement play method that will call its ancestor class
 * @param x
 * @return
 */
Card * Reinforcement::play(Player x) {
   return this->play(x);
}

/**
 * Inside the print method of the reinforcement class
 */
void Reinforcement::print() const {
    cout << "The type of this card is : " <<this->_type << endl;
}


Blockade::Blockade() : Card(){



}

string Blockade::GetType() {
    return this->_type;
}

Blockade::~Blockade() {

}

Blockade::Blockade(string  type) :  Card(type),_type(type){


    this->_type = type;
}

Blockade::Blockade(const Blockade& e) :Card(e){

    this->_type = e._type;
}

Blockade& Blockade::operator=(const Blockade& e){

    Card::operator=(e);
    this->_type = e._type;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Blockade& e){



    return stream << "Card details, type: " << e._type << endl;
}

Card * Blockade::play(Player x) {
    return this->play(x);
}

void Blockade::print() const {
    cout << "The type of this card is : " <<this->_type << endl;
}


Airlift::Airlift() : Card(){


}

Airlift::~Airlift() {

}

string Airlift::GetType() {
    return this->_type;
}

Airlift::Airlift(string  type) :  Card(type),_type(type){

    this->_type = type;
}

Airlift::Airlift(const Airlift& e) :Card(e){

    this->_type = e._type;
}

Airlift& Airlift::operator=(const Airlift& e){

    Card::operator=(e);
    this->_type = e._type;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Airlift& e){



    return stream << "Card details, type:" << (e._type) << endl;
}

Card*  Airlift::play(Player x) {
    return this->play(x);
}

void Airlift::print() const {
    cout << "The type of this card is : " <<this->_type << endl;
}

Diplomacy::Diplomacy() : Card(){




}

Diplomacy::~Diplomacy() {

}

Diplomacy::Diplomacy(string   type) :  Card(type),_type(type){


    this->_type = _type;

}

string Diplomacy::GetType() {
    return this->_type;
}

Diplomacy::Diplomacy(const Diplomacy& e) :Card(e){


    this->_type = e._type;
}

Diplomacy& Diplomacy::operator=(const Diplomacy& e){

    Card::operator=(e);
    this->_type = e._type;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Diplomacy& e){


    return stream << "Card details, type:" << e._type << endl;
}

Card* Diplomacy::play(Player x) {
   return this->play(x);
}

void Diplomacy::print() const {
    cout << "The type of this card is : " <<_type << endl;
}

Hand::Hand(){

}

Hand::~Hand() {

    for(auto & i : this->_collection){
        if (i!= nullptr){
            delete i;
            i=nullptr;
        }
    }
}

 Hand::Hand(vector<Card*>  collection) {
     for(int i=0;i<collection.size();i++){
        this->_collection.push_back(collection[i])   ;
     }
}

Hand::Hand(const Hand& e){


    int index =1;
    for (Card* i: (e._collection) ) {


        string type = i->GetType();
        if(type == "Airlift") {

            Airlift a = Airlift(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }
        if(type == "Bomb") {

            Bomb a = Bomb(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }
        if(type == "Blockade") {

            Blockade a = Blockade(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }

        if(type == "Reinforcement") {

            Reinforcement a = Reinforcement(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }

        if(type == "Diplomacy") {

            Diplomacy a = Diplomacy(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }
    }

    cout << " " << endl;
}

Hand& Hand::operator=(const Hand& e){

    int index =1;
    for (Card* i: (e._collection) ) {

        string type = i->GetType();
        if(type == "Airlift") {

            Airlift a = Airlift(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }
        if(type == "Bomb") {

            Bomb a = Bomb(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }
        if(type == "Blockade") {

            Blockade a = Blockade(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }

        if(type == "Reinforcement") {

            Reinforcement a = Reinforcement(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }

        if(type == "Blockade") {

            Blockade a = Blockade(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }

        if(type == "Diplomacy") {

            Diplomacy a = Diplomacy(type) ;
            Card * T1 = new Card (a);
            this->_collection.push_back(T1);
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Hand& e){



    int index =1;
    for (auto element: e._collection) {

        stream << "This is card number " << index << " ,the type of this card is "   <<(element->GetType()) << " " << endl;
        index++;
    }
    return stream;
}
/**
 * Returns the colleciton of this hand
 * @return
 */
vector<Card*>  Hand::GetCollection() {
    return _collection;
}

void Hand::printCollection() {

    cout << "Printing the hand " << endl;
    cout << "The size is "<<_collection.size() << endl;
    int index =1;
    for (Card* i: (_collection) ) {
        cout << "------------------------" << endl;
        cout << "Card Number  " << index << " " <<endl;
        cout << "Here is the Adress of the pointer " <<i << endl;
        i->print();
        index++;
        cout << "------------------------" << endl;

    }

    cout << " " << endl;
 }

 /**
  * Adding a new card in the hand
  * @param c
  */
void Hand::Add(Card *c){

    _collection.push_back(c);
}

/**
 * This method removes a card from the hand
 * @param c
 */
void Hand::remove(Card* c){

     cout <<endl;
    cout <<endl;


    int index =0;
    for (Card* i: (_collection) ) {

        if(i == c) {
            _collection.erase(_collection.begin()+index);

        }
        index++;
    }

    cout <<endl;
    cout <<endl;
}

Deck::Deck(){

    //Maybe delete that location on the heap after
     //see how to initilaize this after

    cout << "Inside default constructor of Deck class" << endl;
}


Deck::~Deck() {


    for(auto & i : this->_deck){
        if (i!= nullptr){
            delete i;
            i=NULL;
        }
    }

}

Deck::Deck(vector<Card*>  deck) {

    int index =1 ;
    for (Card* i: (deck) ) {


        string type = i->GetType();
        if(type == "Airlift") {

            Airlift a = Airlift(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }
        if(type == "Bomb") {

            Bomb a = Bomb(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }
        if(type == "Blockade") {

            Blockade a = Blockade(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }

        if(type == "Reinforcement") {
            Reinforcement a = Reinforcement(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }

        if(type == "Blockade") {
            Blockade a = Blockade(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }

        if(type == "Diplomacy") {

            Diplomacy a = Diplomacy(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }
        index++;
    }
}

Deck::Deck(const Deck& e) {


    int index =1;
    for (Card* i: (e._deck) ) {


        string type = i->GetType();
        if(type == "Airlift") {

            Airlift a = Airlift(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }
        if(type == "Bomb") {

            Bomb a = Bomb(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }
        if(type == "Blockade") {

            Blockade a = Blockade(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }

        if(type == "Reinforcement") {

            Reinforcement a = Reinforcement(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }

        if(type == "Diplomacy") {

            Diplomacy a = Diplomacy(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }
        index++;
    }

}

Deck& Deck::operator=(const Deck& e){


    int index = 1;
    for (Card* i: (e._deck) ) {


        string type = i->GetType();
        if(type == "Airlift") {

            Airlift a = Airlift(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }
        if(type == "Bomb") {

            Bomb a = Bomb(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }
        if(type == "Blockade") {

            Blockade a = Blockade(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }

        if(type == "Reinforcement") {

            Reinforcement a = Reinforcement(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }


        if(type == "Diplomacy") {

            Diplomacy a = Diplomacy(type) ;
            Card * T1 = new Card (a);
            this->_deck.push_back(T1);
        }
        index++;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Deck& e){


     int index = 1;
    for (Card * element: e._deck) {

        stream << "This is card number: " << index << " ,the type of this card is "   <<(element->GetType()) << " " << endl;

        index++;
    }
    return stream;

}

vector<Card*> Deck::GetDeck() {
    return _deck;
}

void Deck::printDeck(){

    cout << "Printing the Deck " << endl;
    cout << "The size is "<<_deck.size() << endl;

    int index =1;
    for (Card* i: (_deck) ) {

        cout << "------------------------" << endl;
        cout << "Card Number  " << index << " " <<endl;
        cout << "Here is the Adress of the pointer " <<i << endl;
        i->print();
        index++;
        cout << "------------------------" << endl;

    }
    cout << " " << endl;

 }

void Deck::Add(Card *c){



       _deck.push_back(c);
 }

void Deck::remove(Card c){

    Card * cpointer = &c;

    _deck.push_back(cpointer);
}

/**
 * This method will draw and return a random card from the Deck
 * @return
 */
Card* Deck::draw()   {

     cout << endl;
    cout << endl;

    printDeck();

    vector<Card*> CurrentHand = GetDeck();

    int size =  CurrentHand.size();


    int index =  rand() % (size-1) + 0;


      int count =0;

      for (Card* i: (_deck) ) {

        if(count == index) {

            cout << "The Picked Card is card number : " << (count+1)  << endl;
            i->print();
            _deck.erase(_deck.begin()+count);

            return i;
        }
        count++;

    }

return NULL;
}

