//
// Created by Eve Gagnon on 2021-10-08.
//

#ifndef COMP345_GAMEENGINE_H
#define COMP345_GAMEENGINE_H

//
// Created by Eve Gagnon on 2021-09-26.
//

#include <iostream>

// Makes sure the content is read only once if the file is read more than one.


using namespace std;

class GameEngine {
public:
    GameEngine();
    virtual ~GameEngine();
    // Accessors
    const bool& getQuit() const;
    string getState();
    // Modifiers
    void setQuit();
    void setState(string currentState);
    // Functions
    static void printMenu();
private:
    bool quit;
    string state;

};

class Command {
public:
    // Constructor takes the current
    Command();
    // Empty constructor
    virtual ~Command();

    static void start();
    static void loadMap();
    static void validateMap();
    static void addPlayer();
    static void assignCountries();
    static void issueOrder();
    static void endIssueOrders(); // endissueorders and endexecorders pretty much just end the phase so we can move on
    // to the next state, allowing the user to enter a different set of commands.
    static void execOrder();
    static void endExecOrders();

    static void win();
    static void play();
    static void end();
};


#endif //COMP345_GAMEENGINE_H