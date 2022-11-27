#ifndef MEMORIA_DADOS_H
#define MEMORIA_DADOS_H

#include "Dado.h"

using namespace std;

class MemoriaDeDados{
private:
    int tamanho;
    int posicao;
    Dado** dados;

public:
    MemoriaDeDados(int tamanho);
    virtual ~MemoriaDeDados();
    int getTamanho();
    Dado* ler(int posicao);
    bool escrever(int posicao, Dado* d);
    void imprimir();

};

#endif // MEMORIA_DADOS_H