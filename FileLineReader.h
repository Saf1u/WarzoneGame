//
// Created by Safwan Ahmed on 2021-11-06.
//

#ifndef UNTITLED_FILECOMMANDPROCESSOR_H
#define UNTITLED_FILECOMMANDPROCESSOR_H
#include <string>
#include "GameEngine.h"
#include "fstream"
using namespace std;

class FileLineReader {
public:
     fstream* file;
    FileLineReader(const string&);
    ~FileLineReader();
    Command* readLineFromFile();
    FileLineReader& operator =(const FileLineReader &t);

};







#endif //UNTITLED_FILECOMMANDPROCESSOR_H
