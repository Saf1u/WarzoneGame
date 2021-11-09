//
// Created by Safwan Ahmed on 2021-11-06.
//

#ifndef UNTITLED_FILECOMMANDPROCESSOR_H
#define UNTITLED_FILECOMMANDPROCESSOR_H
#include <string>
#include "GameEngine.h"
#include "fstream"
using namespace std;

class FileCommandProcessor {
public:
     fstream* file;
    FileCommandProcessor(const string&);
    ~FileCommandProcessor();
    Command* readCommand();
    FileCommandProcessor& operator =(const FileCommandProcessor &t);

};







#endif //UNTITLED_FILECOMMANDPROCESSOR_H
