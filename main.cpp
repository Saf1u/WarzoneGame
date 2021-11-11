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

    //Uncomment to demo part1
//    string file;
//    CommandProcessor* p;
//    if (strcmp(argv[1],"-file")==0){
//        file=argv[2];
//        FileCommandProcessor *c=new FileCommandProcessor(file);
//        p=new FileCommandProcessorAdapter(c);
//
//    }
//     if (strcmp(argv[1],"-console")==0){
//            p=new CommandProcessor();
//        }
//
// for(;;) {
//     Command *e = p->getCommand();
//     if (e==nullptr){
//         exit(0);
//     }
//
//     p->validate(e);
//     cout << e->name << "-----" << endl;
//     cout << e->effect << endl;
// }
}
