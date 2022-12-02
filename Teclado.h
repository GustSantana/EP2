#ifndef TECLADO_H
#define TECLADO_H

#include <string>
#include <iostream>
#include "Dispositivo.h" 

using namespace std;

class Teclado : public Dispositivo {
private:
    int numero;
    
public:
    Teclado();
    virtual ~Teclado();
    virtual Dado* ler(); 
    virtual void escrever(Dado* d);

};

#endif  // TECLADO_H