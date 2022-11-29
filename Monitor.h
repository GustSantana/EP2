#ifndef MONITOR_H
#define MONITOR_H

#include <string>
#include <iostream> 
#include "Dispositivo.h"

using namespace std;

class Monitor : public Dispositivo {
public:
    Monitor();
    virtual ~Monitor();
    Dado* ler(); 
    virtual void escrever(Dado* d);

};

#endif  // MONITOR_H