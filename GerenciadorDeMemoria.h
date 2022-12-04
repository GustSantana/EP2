#ifndef GERENCIADOR_DE_MEMORIA_H
#define GERENCIADOR_DE_MEMORIA_H

#include <iostream> 
#include <fstream>
#include "MemoriaRAM.h"
#include "Instrucao.h"
#include <list>

using namespace std;

class GerenciadorDeMemoria {
public:
    GerenciadorDeMemoria();
    virtual ~GerenciadorDeMemoria(); 
    virtual void load(string arquivo, MemoriaRAM* m); 
    virtual void dump(string arquivo, MemoriaRAM* m); 

};

#endif  // GERENCIADOR_DE_MEMORIA_H