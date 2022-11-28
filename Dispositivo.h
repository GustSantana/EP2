#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include "Dado.h"
#include <string>
#include <iostream> 

using namespace std;

class Dispositivo {

public:
    Dispositivo();
    virtual ~Dispositivo(); 
    virtual Dado* ler(); 
    virtual void escrever(Dado* d);
};

#endif  // DISPOSITIVO_H