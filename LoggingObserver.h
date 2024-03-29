//
// Created by Safwan Ahmed on 2021-11-12.
//

#include <string>
using namespace std;

#ifndef UNTITLED_LOGGINGOBSERVER_H
#define UNTITLED_LOGGINGOBSERVER_H

class ILoggable{
public:
    virtual string stringToLog()=0;
};
class Observer {
public:
    virtual void Update(ILoggable&)=0;
};
class Subject {
public:
    Observer* o;
    virtual void Attach(Observer* o);
    virtual void Notify(ILoggable&);
    Subject();
   virtual ~Subject();
};


class LoggingObserver: public Observer {
public:
   const string filename="../gamelog.txt";
    void Update(ILoggable&);
};

#endif //UNTITLED_LOGGINGOBSERVER_H
