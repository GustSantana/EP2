#ifndef MEMORIA_DE_INSTRUCOES_H
#define MEMORIA_DE_INSTRUCOES_H

#include "Instrucao.h"
#include "Dado.h"
#include <string>

using namespace std;

class MemoriaDeInstrucoes{
private:
    int tamanho;
    int posicao;
    Instrucao** vetorInstrucoes;

public:
    MemoriaDeInstrucoes(int tamanho);
    virtual ~MemoriaDeInstrucoes();
    int getTamanho();
    Instrucao* ler(int posicao);
    bool escrever(int posicao, Instrucao* d);

};

#endif  // MEMORIA_DE_INSTRUCOES_H