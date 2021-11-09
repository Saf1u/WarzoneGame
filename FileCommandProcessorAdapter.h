//
// Created by Safwan Ahmed on 2021-11-06.
//

#ifndef UNTITLED_FILECOMMANDPROCESSORADAPTER_H
#define UNTITLED_FILECOMMANDPROCESSORADAPTER_H
#include <string>
#include "GameEngine.h"
#include "fstream"
#include "FileCommandProcessor.h"
#include "CommandProcessor.h"

class FileCommandProcessorAdapter:public CommandProcessor {
public:
   FileCommandProcessor* FileProcessor;

   FileCommandProcessorAdapter(FileCommandProcessor*);
   Command* readCommand();
};


#endif //UNTITLED_FILECOMMANDPROCESSORADAPTER_H
