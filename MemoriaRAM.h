#ifndef MEMORIA_RAM_H
#define MEMORIA_RAM_H

#include "Memoria.h"
#include <iostream>
#include <list>

using namespace std;

class MemoriaRam : public Memoria {
    private:
    int tamanho;
    int posicao;
    Dado** vetorDados;

    public:
        MemoriaRam(int tamanho);
        virtual ~MemoriaRam();
        virtual void escrever(list<Dado*>* dados); 

        int getTamanho(); 
        Dado* ler(int posicao);
        void escrever(int posicao, Dado* d);
};

#endif //MEMORIA_RAM_H