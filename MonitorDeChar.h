#ifndef MONITOR_DE_CHAR_H
#define MONITOR_DE_CHAR_H

#include <string>
#include <iostream> 
#include "Monitor.h"

using namespace std;

class MonitorDeChar : public Monitor {
public:
    MonitorDeChar();
    virtual ~MonitorDeChar();
    virtual Dado* ler(); 
    virtual void escrever(Dado* d);

};

#endif  // MONITOR_DE_CHAR_H