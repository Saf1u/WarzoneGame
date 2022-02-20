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
#include "LoggingObserver.h"


// Makes sure the content is read only once if the file is read more than one.


using namespace std;
class CommandProcessor;
class Queue;
class Deck;
class Player;
class GameEngine: public ILoggable,public Subject {
public:
    string stringToLog();
    Queue* queue;
    string LogMessage;
    void transition(string);
    CommandProcessor *c;
    GameEngine();
   bool redistribute(Player *p);
    bool readFromFile ;
    string filename;
    GameEngine(GameEngine const&);
    // Accessors
    // Functions
    static void printMenu();
    Map* map;
    Deck* gameDeck;
    vector<Player*> players;
    void RemovePlayer(Player * p);
    vector<Player*> listOfTournamentPlayers;
    vector<string>strategies;
    vector<string> mapsToLoad;
    int numbersToPlay;
    int numberOfTurns;
    bool isTournament=false;
    void start();
    bool loadMap(const string&);
    bool validateMap();
    bool addPlayer(string);
    bool assignCountries();
    void issueOrder();
    bool quit();
    bool replay();
    bool gameStart();
    bool draw=false;
    int numberOftimesHecannotattack=0;
     void win();
     void tournamentSetup(string);
     void play();
     void end();
     void startupphase();
     void verification();
     void endIssueOrders(); // endissueorders and endexecorders pretty much just end the phase so we can move on
    // to the next state, allowing the user to enter a different set of commands.
     void execOrder();
     void endExecOrders();
    ~GameEngine();
    GameEngine& operator =(const GameEngine &m);
    void issueOrdersPhase();

    bool executeOrdersPhase();

    void reinforcementPhase();

    string mainGameLoop();

    int gameReinforcementPool = 2 * 60;
    unordered_map<string, unordered_map<string, string>> gameBlock;



};
 class Queue {
public:
    // Initialize front and rear


    // Circular Queue
    vector<Player*> queue;


    void enQueue(Player* player);
    Player* deQueue();

};

ostream&  operator <<(ostream &strm,const GameEngine &m);
class Command: public ILoggable,public Subject {

public:
    // Constructor takes the current
    string name;
    Command();
    Command(string);
    string LogMessage;
    void saveEffect(string);
    Command(Command const &);
    string stringToLog();
    string effect;
    // Empty constructor
     ~Command();
    //bool executeCommand();




};
ostream&  operator <<(ostream &strm,const Command &m);






#endif //COMP345_GAMEENGINE_H