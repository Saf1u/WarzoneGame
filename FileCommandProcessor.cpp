//
// Created by Safwan Ahmed on 2021-11-06.
//

#include "FileCommandProcessor.h"


Command* FileCommandProcessor::readCommand(){
    string command;
    cout<<"enter command:"<<endl;
    if (((this->file)->eof())==1) {
        return nullptr;
    }
        getline(*(this->file),command,'\n');

    Command *c=new Command(command);
    return c;

}

FileCommandProcessor::FileCommandProcessor(const string& filename) {
   fstream  *strm=new fstream(filename);
    this->file=strm;
}

FileCommandProcessor::~FileCommandProcessor() {
    delete this->file;
    this->file=nullptr;
}

