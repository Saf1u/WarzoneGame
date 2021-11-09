#include <iostream>
#include "FileCommandProcessorAdapter.h"
#include "FileCommandProcessor.h"


int main(int argc,char **argv) {
    for (int i=0;i<argc;i++){
        cout<<argv[i]<<i<<endl;
    }
    string file;
    CommandProcessor* p;
    if (strcmp(argv[1],"-filename")==0){
        file=argv[2];
        FileCommandProcessor *c=new FileCommandProcessor(file);
        p=new FileCommandProcessorAdapter(c);

    }
     if (strcmp(argv[1],"-console")==0){
            p=new CommandProcessor();
        }

 for(;;) {
     Command *e = p->getCommand();
     if (e==nullptr){
         exit(0);
     }

     p->validate(e);
     cout << e->name << "-----" << endl;
     cout << e->effect << endl;
 }
}
