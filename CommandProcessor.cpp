//
// Created by Safwan Ahmed on 2021-11-03.
//

#include "CommandProcessor.h"
#include <fstream>

using namespace std;


string CommandProcessor::stringToLog(){
    return "COMMAND PROCESSOR LOG:"+LogMessage;
}
//stores the command internally in a collection of Command objects
void CommandProcessor::saveCommand(Command * com) {
    this->commands.push_back(com);
    this->LogMessage="The following Command was just saved: "+com->name;
    Notify(*this);

}
/*
 * validating tournament mode
 * list of maps, strategies
 * games to be played
 * number of turns for each game*/
bool CommandProcessor::validateTournament(string command){
    int z=command.find("-M");
    int j=command.find("P");


    string maps=command.substr(z+3,j-(z+5));
    z=command.find("P");
    j=command.find("G");
    string strategy=command.substr(z+2,j-(z+4));
    z=command.find("G");
    j=command.find("D");
    string gamesToPlay=command.substr(z+2,j-(z+4));
    z=command.find("D");
    string turns=command.substr(z+2,command.length()-1);

    vector<string> mapsToLoad=tokenize(maps);
    vector<string> strategies= tokenize(strategy);
    for(int i=0;i<mapsToLoad.size();i++){
        mapsToLoad[i]=mapsToLoad[i];
    }
    if(mapsToLoad.size()<1||mapsToLoad.size()>5){
        return false;
    }

    if(strategies.size()<2||strategies.size()>4){
        return false;
    }
    int games= stoi(gamesToPlay);
    if(games<1||games>5){
        return false;
    }

    if(games<1||games>5){
        return false;
    }
    int numOfTurns= stoi(turns);

    if(numOfTurns<10||numOfTurns>50){
        return false;
    }
    return  true;

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
    (transitions)["start"]["tournament"] = "addplayer";
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
    if (com->name.find("tournament")==0){
        return validateTournament(com->name);
    }
    string name=com->name;
   if (com->name.find("loadmap")==0){
      name="loadmap" ;
   }
    if (com->name.find("addplayer")==0){
        name="addplayer" ;
    }

    if (transitions[currentState][name].empty()){



        return false;
    }else{


        if (com->name.find("loadmap")==0){


            return true;
        }
        if (com->name.find("addplayer")==0){


            return true;
        }
        if(com->name=="validatemap"){


            return true;
        }
        if(com->name=="gamestart"){


            return true;
        }

    }

}

Command* CommandProcessor::getCommand() {
   Command *c=readCommand();
   if (c!= nullptr){
       Subject *sub=c;
       sub->Attach(this->o);
       saveCommand(c);
   }

   return c;
}
//gets commands from the console as a string
Command* CommandProcessor::readCommand(){
    string command;
    cout<<"enter command:"<<endl;
    getline(cin,command,'\n');
    Command *c=new Command(command);

    return c;

}



