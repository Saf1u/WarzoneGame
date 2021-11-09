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
    string name;
    Command();
    Command(string);
    void saveEffect(string);
    string effect;
    // Empty constructor
    virtual ~Command();
    //bool executeCommand();
    static void start();
    static bool loadMap();
    static bool validateMap();
    static bool addPlayer();
    static bool assignCountries();
    static void issueOrder();
    static bool quit();
    static bool replay();
    static bool gameStart();

    static void endIssueOrders(); // endissueorders and endexecorders pretty much just end the phase so we can move on
    // to the next state, allowing the user to enter a different set of commands.
    static void execOrder();
    static void endExecOrders();

    static void win();
    static void play();
    static void end();
    static string currentState;
    static  unordered_map<string, unordered_map<string, string>> transitions;
    static unordered_map<string, unordered_map<string, string>>* initializeMap();
};







#endif //COMP345_GAMEENGINE_H