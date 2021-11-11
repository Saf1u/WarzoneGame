//
// Created by Safwan Ahmed on 2021-11-03.
//

#include "CommandProcessor.h"
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

CommandProcessor::CommandProcessor() {
    (transitions)["start"]["loadmap"] = "maploaded";
    (transitions)["maploaded"]["loadmap"] = "maploaded";
    (transitions)["maploaded"]["validatemap"] = "mapvalidated";
    (transitions)["mapvalidated"]["addplayer"] = "playeradded";
    (transitions)["playeradded"]["addplayer"] = "playeradded";
    (transitions)["playeradded"]["gamestart"] = "assignreinforcement";
    (transitions)["assignreinforcement"]["issueorder"] = "issueorder";
    (transitions)["issueorder"]["issueorder"] = "issueorder";
    (transitions)["issueorder"]["endissueorder"] = "execorder";
    (transitions)["execorder"]["execorder"] = "execorder";
    (transitions)["execorder"]["endexecorder"] = "assignreinforcement";
    (transitions)["execOrder"]["win"] = "win";
    (transitions)["win"]["end"] = "quit";
    (transitions)["win"]["play"] = "start";
    currentState="start";

}
void CommandProcessor::makeTransition(string movement){
    string action=transitions[currentState][movement];
      currentState=action;

}

bool CommandProcessor::validate(Command * com ) {
    string name=com->name;
   if (com->name.find("loadmap")==0){
      name="loadmap" ;
   }
    if (com->name.find("addplayer")==0){
        name="addplayer" ;
    }

    if (transitions[currentState][name].empty()){
        com->saveEffect("wrong transition");


        return false;
    }else{


        if (com->name.find("loadmap")==0){

            com->saveEffect("maploaded");
            return true;
        }
        if (com->name.find("addplayer")==0){

            com->saveEffect("playeradded");
            return true;
        }
        if(com->name=="validatemap"){

            com->saveEffect("mapvalidated");
            return true;
        }
        if(com->name=="gamestart"){

            com->saveEffect("gamestarted");
            return true;
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



