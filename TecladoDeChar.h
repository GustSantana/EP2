#ifndef TECLADO_DE_CHAR_H
#define TECLADO_DE_CHAR_H

#include <string>
#include <iostream>
#include "Teclado.h" 

using namespace std;

class TecladoDeChar : public Teclado {
private:
    char palavra;
    
public:
    TecladoDeChar();
    virtual ~TecladoDeChar();
    virtual Dado* ler(); 
    virtual void escrever(Dado* d);

};

#endif  // TECLADO_DE_CHAR_H