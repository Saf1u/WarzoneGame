//
// Created by Safwan Ahmed on 2021-11-06.
//
#include "FileLineReader.h"


Command* FileLineReader::readLineFromFile(){
    string command;
    cout<<"enter command:"<<endl;
    if (((this->file)->eof())==1) {
        return nullptr;
    }
    getline(*(this->file),command,'\n');

    Command *c=new Command(command);
    return c;

}

FileLineReader::FileLineReader(const string& filename) {
    fstream  *strm=new fstream(filename);
    this->file=strm;
}

FileLineReader::~FileLineReader() {
    delete this->file;
    this->file=nullptr;
}
