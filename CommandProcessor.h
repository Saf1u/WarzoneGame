//
// Created by Safwan Ahmed on 2021-11-03.
//

#ifndef WARZONEGAME_COMMANDPROCESSOR_H
#define WARZONEGAME_COMMANDPROCESSOR_H

#include "GameEngine.h"
#include <vector>



command* function readCommand(){
   input string <<cin
   Command(input)
   savecommand(command)
}

using namespace std;

class CommandProcessor {
private:
    vector<Command*> commands;
   virtual Command* readCommand();
    void saveCommand(Command*);

public:
    Command* getCommand();
    void validate(Command *);


  virtual  ~CommandProcessor();
};


#endif //WARZONEGAME_COMMANDPROCESSOR_H
