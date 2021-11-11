//
// Created by Safwan Ahmed on 2021-11-03.
//

#ifndef WARZONEGAME_COMMANDPROCESSOR_H
#define WARZONEGAME_COMMANDPROCESSOR_H

#include "GameEngine.h"
#include <vector>





using namespace std;

class CommandProcessor {
private:
    vector<Command*> commands;
   virtual Command* readCommand();
    void saveCommand(Command*);
    string currentState;
    unordered_map<string, unordered_map<string, string>> transitions;

public:
    CommandProcessor();
    Command* getCommand();
    bool validate(Command *);
    void makeTransition(string);


  virtual  ~CommandProcessor();
};


#endif //WARZONEGAME_COMMANDPROCESSOR_H
