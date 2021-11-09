//
// Created by Safwan Ahmed on 2021-11-03.
//

#include "CommandProcessor.h"
#include "GameEngine.h"
#include <fstream>

using namespace std;

void CommandProcessor::saveCommand(Command * com) {
    this->commands.push_back(com);
}

 CommandProcessor::~CommandProcessor() {
    for(auto & i : commands){
        if (i!= nullptr){
            delete i;
            i= nullptr;
        }

    }
}

void CommandProcessor::validate(Command * com ) {
    string name=com->name;
   if (com->name.find("loadmap")==0){
      name="loadmap" ;
   }
    if (com->name.find("addplayer")==0){
        name="addplayer" ;
    }
    if (com->transitions[com->currentState][name]==""){
        com->saveEffect("wrong transition");
    }else{
        string action=com->transitions[com->currentState][name];
        com->currentState=action;

        if (com->name.find("loadmap")==0){
            com->loadMap();
            com->saveEffect("maploaded");
            return;
        }
        if (com->name.find("addplayer")==0){
            com->addPlayer();
            com->saveEffect("playeradded");
            return;
        }
        if(com->name=="valiadtemap"){
            com->validateMap();
            com->saveEffect("mapvalidated");
            return;
        }
        if(com->name=="gamestart"){
            com->gameStart();
            com->saveEffect("gamestarted");
            return;
        }
        if(com->name=="replay"){
            com->replay();
            com->saveEffect("replayed");
            return;
        }
        if(com->name=="quit"){
            com->quit();
            com->saveEffect("it quit");
            return;
        }
    }

}

Command* CommandProcessor::getCommand() {
   Command *c=readCommand();
   if (c!= nullptr){
       saveCommand(c);
   }

   return c;
}
Command* CommandProcessor::readCommand(){
    string command;
    cout<<"enter command:"<<endl;
    getline(cin,command,'\n');
    Command *c=new Command(command);

    return c;

}



