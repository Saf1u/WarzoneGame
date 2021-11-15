//
// Created by Safwan Ahmed on 2021-11-12.
//

#include "LoggingObserver.h"
#include <fstream>

Subject::Subject() {

}


Subject::~Subject() {
    delete o;
}
//method to trigger the writing of an entry in the log file
void Subject::Notify(ILoggable &c) {
    this->o->Update(c);
}

void Subject::Attach(Observer *o) {
    this->o = o;
}


void LoggingObserver::Update(ILoggable &c) {
    string logMessage = c.stringToLog();
    fstream strm(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    strm << logMessage << endl;
    strm.close();
}