#include <iostream>
#include "FileCommandProcessorAdapter.h"
#include "FileCommandProcessor.h"
#include "GameEngine.h"


int main(int argc,char **argv) {
    //part2
GameEngine *c=new GameEngine;
    if (strcmp(argv[1],"-file")==0){
       c->readFromFile=true;
       c->filename=argv[2];
    }
c->startupphase();


}
