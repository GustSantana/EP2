#ifndef UNIDADE_DE_CONTROLE_H
#define UNIDADE_DE_CONTROLE_H

#include <string>
#include <iostream>
#include "Memoria.h"
#include "BancoDeRegistradores.h"
#include "Instrucao.h"

using namespace std;

class UnidadeDeControle {
private:
    BancoDeRegistradores* registradores;
    Memoria* memoria;
    int PC;
    
public:
    UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria);
    virtual ~UnidadeDeControle(); 
    virtual BancoDeRegistradores* getBancoDeRegistradores(); 
    virtual Memoria* getMemoria(); 
    virtual int getPC(); 
    virtual void setPC(int pc); 
    virtual void executarInstrucao(); 

};

#endif  // UNIDADE_DE_CONTROLE_H


