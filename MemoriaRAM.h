#ifndef MEMORIA_RAM_H
#define MEMORIA_RAM_H

#include "Memoria.h"
#include "Instrucao.h"
#include <iostream>
#include <list>

using namespace std;

class MemoriaRAM : public Memoria {
    private:
    int tamanho;
    int posicao;
    Dado** vetorDados;

    public:
        MemoriaRAM(int tamanho);
        virtual ~MemoriaRAM();
        virtual void escrever(list<Dado*>* dados); 

        int getTamanho(); 
        Dado* ler(int posicao);
        void escrever(int posicao, Dado* d);
        void imprimir();
};

#endif //MEMORIA_RAM_H