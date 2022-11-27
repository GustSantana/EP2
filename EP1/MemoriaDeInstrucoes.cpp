#include "MemoriaDeInstrucoes.h"
#include <iostream>

MemoriaDeInstrucoes::MemoriaDeInstrucoes(int tamanho) : tamanho (tamanho) {
    vetorInstrucoes = new Instrucao*[tamanho];

    for(int i = 0; i < tamanho; i++)
        vetorInstrucoes[i] = NULL;
    
}

MemoriaDeInstrucoes::~MemoriaDeInstrucoes(){
    for(int i = 0; i < tamanho; i++)
        delete vetorInstrucoes[i];
    
    delete[] vetorInstrucoes;
}

int MemoriaDeInstrucoes::getTamanho(){
    return tamanho;
}

Instrucao* MemoriaDeInstrucoes::ler(int posicao){
    if (posicao < 0 || posicao >= tamanho)
        return NULL;

    else 
        return vetorInstrucoes[posicao];
}

bool MemoriaDeInstrucoes::escrever(int posicao, Instrucao* d){
    if (posicao >= 0 && posicao < tamanho){
        if (vetorInstrucoes[posicao] != NULL){
            delete vetorInstrucoes[posicao];
            vetorInstrucoes[posicao] = d;
        }
        else vetorInstrucoes[posicao] = d;
        return true;
    }
    return false;
}