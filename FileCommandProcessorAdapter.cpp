//
// Created by Safwan Ahmed on 2021-11-06.
//

#include "FileCommandProcessorAdapter.h"

FileCommandProcessor& FileCommandProcessor::operator =(const FileCommandProcessor &t){
    this->file=t.file;
    return  *this;
}
FileCommandProcessorAdapter::FileCommandProcessorAdapter( FileCommandProcessor *proc){
this->FileProcessor=proc;

}

Command * FileCommandProcessorAdapter::readCommand() {
    return this->FileProcessor->readCommand();
}



