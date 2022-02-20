//
// Created by Safwan Ahmed on 2021-11-06.
//

#include "FileCommandProcessorAdapter.h"

FileLineReader& FileLineReader::operator =(const FileLineReader &t){
    this->file=t.file;
    return  *this;
}
FileCommandProcessorAdapter::FileCommandProcessorAdapter( FileLineReader *proc){
    this->FileProcessor=proc;

}

Command * FileCommandProcessorAdapter::readCommand() {
    return this->FileProcessor->readLineFromFile();
}





