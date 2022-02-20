//
// Created by Safwan Ahmed on 2021-11-06.
//

#ifndef UNTITLED_FILECOMMANDPROCESSORADAPTER_H
#define UNTITLED_FILECOMMANDPROCESSORADAPTER_H
#include <string>
#include "GameEngine.h"
#include "fstream"
#include "FileLineReader.h"
#include "CommandProcessor.h"

class FileCommandProcessorAdapter:public CommandProcessor {
public:
   FileLineReader* FileProcessor;

   FileCommandProcessorAdapter(FileLineReader*);
   Command* readCommand();
};


#endif //UNTITLED_FILECOMMANDPROCESSORADAPTER_H
