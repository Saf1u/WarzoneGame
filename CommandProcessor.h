//
// Created by Safwan Ahmed on 2021-11-03.
//

#ifndef WARZONEGAME_COMMANDPROCESSOR_H
#define WARZONEGAME_COMMANDPROCESSOR_H

#include "GameEngine.h"
#include <vector>





using namespace std;

class CommandProcessor: public ILoggable,public Subject{
private:
    vector<Command*> commands;
    string LogMessage;
    virtual Command* readCommand();
    string  stringToLog();
    void saveCommand(Command*);
    string currentState;
    unordered_map<string, unordered_map<string, string>> transitions;



public:
    bool validateTournament(string t);
    CommandProcessor();
    Command* getCommand();
    bool validate(Command *);
    void makeTransition(string);


  virtual  ~CommandProcessor();
};


#endif //WARZONEGAME_COMMANDPROCESSOR_H
