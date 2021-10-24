
//#ifndef CARDS_H
//#define CARDS_H

#pragma once

#include<string>
#include <vector>
#include<memory>
#include "Player.h"
#include "Orders.h"

using namespace std;

class Player;
class Card{
public:

    Card();

    virtual ~Card();

    explicit Card(string  type);

    Card(const Card& e);
    Card& operator =(const Card& e);

    friend std::ostream& operator <<(std::ostream& stream, const Card&  e);

    Card* play(Player x);

   virtual string GetType();

   virtual void print() const;

private:

    string  _type{"General"};
};

class Bomb : public Card{
public:
    Bomb();

    ~Bomb();


   Bomb(string  type);

    Bomb(const Bomb& e);
    Bomb& operator =(const Bomb& e);

    friend std::ostream& operator <<(std::ostream& stream, const Bomb& e);

    Card* play(Player x);

    string GetType();

    virtual void print() const;

private:
    string  _type {"Bomb"};
};


class Reinforcement : public Card{
public:
    Reinforcement();

    ~Reinforcement();

    Reinforcement(string  type);

    Reinforcement(const Reinforcement& e);
    Reinforcement& operator =(const Reinforcement& e);

    friend std::ostream& operator <<(std::ostream& stream, const Reinforcement& e);

    string GetType();

    Card* play(Player x);

    virtual void print() const;

private:
    string  _type {"Reinforcement"};
};

class Blockade : public Card{
public:
    Blockade();

    ~Blockade();

    Blockade(string  type);

    Blockade(const Blockade& e);
    Blockade& operator =(const Blockade& e);

    friend std::ostream& operator <<(std::ostream& stream, const Blockade& e);

    Card* play(Player x);

    string GetType();

    virtual void print() const;

private:
    string  _type{"Blockade"};
};

class Airlift : public Card{
public:
    Airlift();

    ~Airlift();

    Airlift(string  type);

    Airlift(const Airlift& e);
    Airlift& operator =(const Airlift& e);

    friend std::ostream& operator <<(std::ostream& stream, const Airlift& e);

    Card* play(Player x);

    string GetType();

    virtual void print() const;

private:
    string  _type{"Airlift"};
};

class Diplomacy : public Card{
public:
    Diplomacy();

    ~Diplomacy();

    Diplomacy(string  type);

    string GetType();

    Diplomacy(const Diplomacy& e);
    Diplomacy& operator =(const Diplomacy& e);

    friend std::ostream& operator <<(std::ostream& stream, const Diplomacy& e);

    Card* play(Player x);

    virtual void print() const;

private:
    string  _type{"Diplomacy"};
};


class Hand {
public:
    Hand();

    ~Hand();

    Hand(vector<Card*>  collection);

    vector<Card*>  GetCollection();

    Hand(const Hand& e);
    Hand& operator =(const Hand& e);

    friend std::ostream& operator <<(std::ostream& stream, const Hand& e);

    void printCollection();
    void remove(Card* c);

    void Add(Card c);

private:
   vector<Card*>  _collection;
};

class Deck {
public:
   inline Deck();

    ~Deck();

    Deck(vector<Card*>  deck);

    vector<Card *>  GetDeck();

    Deck(const Deck& e);

    Deck& operator =(const Deck& e);

    friend std::ostream& operator <<(std::ostream& stream, const Deck& e);

    void printDeck();

    Card* draw() ;

    void remove(Card c);

    void Add(Card c);

private:
    vector<Card *>  _deck;
};

//#endif

