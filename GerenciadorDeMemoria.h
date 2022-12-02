#ifndef GERENCIADOR_DE_MEMORIA_H
#define GERENCIADOR_DE_MEMORIA_H

#include <iostream> 
#include "MemoriaRAM.h"

using namespace std;

class GerenciadorDeMemoria {
public:
    GerenciadorDeMemoria();
    virtual ~GerenciadorDeMemoria(); 
    virtual void load(string arquivo, MemoriaRAM* m); 
    virtual void dump(string arquivo, MemoriaRAM* m); 

};

#endif  // GERENCIADOR_DE_MEMORIA_H