#include <iostream>
#include "FileCommandProcessorAdapter.h"
#include "FileLineReader.h"
#include "GameEngine.h"


using namespace std;


int main(int argc,char **argv) {
    auto *c=new GameEngine;
    if (strcmp(argv[1],"-file")==0){

        c->readFromFile=true;
        c->filename=argv[2];

      c->c= new FileCommandProcessorAdapter(new FileLineReader(argv[2]));


    }else{
        c->c=new CommandProcessor;
    }

    Observer *o=new LoggingObserver;
    Subject* sub;
    sub=c->c;
    sub->Attach(o);
    sub=c;
    sub->Attach(o);
    c->startupphase();
    if(!c->isTournament){
        c->mainGameLoop();
    }






    // destroying the GameEngine itself
    delete c;
    c = NULL;
}
