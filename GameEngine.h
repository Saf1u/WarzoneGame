//
// Created by Eve Gagnon on 2021-10-08.
//

#ifndef COMP345_GAMEENGINE_H
#define COMP345_GAMEENGINE_H

//
// Created by Eve Gagnon on 2021-09-26.
//

#include <iostream>
#include <unordered_map>
#include "Player.h"


// Makes sure the content is read only once if the file is read more than one.


using namespace std;

class Deck;
class Player;
class GameEngine {
public:
    GameEngine();
    bool readFromFile ;
    string filename;
    GameEngine(GameEngine const&);
    // Accessors
    // Functions
    static void printMenu();
    Map* map;
    Deck* gameDeck;
    vector<Player*> players;
    Player* p;

    void start();
    bool loadMap(const string&);
    bool validateMap();
    bool addPlayer(string);
    bool assignCountries();
    void issueOrder();
    bool quit();
    bool replay();
    bool gameStart();
     void win();
     void play();
     void end();
     void startupphase();
     void endIssueOrders(); // endissueorders and endexecorders pretty much just end the phase so we can move on
    // to the next state, allowing the user to enter a different set of commands.
     void execOrder();
     void endExecOrders();
    ~GameEngine();
    GameEngine& operator =(const GameEngine &m);


    void issueOrdersPhase();

    bool executeOrdersPhase();

    void reinforcementPhase();

    void mainGameLoop();
};
ostream&  operator <<(ostream &strm,const GameEngine &m);

static class Queue {
public:
    // Initialize front and rear
    Player* rear, front;

    // Circular Queue
    int size;
    Player *circular_queue;

    Queue(int sz) {
        front = rear = -1;
        size = sz;
        circular_queue = new int[sz];
    }
    void enQueue(Player* player);
    int deQueue();
    void displayQueue();
};
class Command {

public:
    // Constructor takes the current
    string name;
    Command();
    Command(string);
    void saveEffect(string);
    Command(Command const &);
    string effect;
    // Empty constructor
     ~Command();
    //bool executeCommand();




};
ostream&  operator <<(ostream &strm,const Command &m);






#endif //COMP345_GAMEENGINE_H