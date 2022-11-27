#include "MemoriaDeDados.h"
#include <iostream>

MemoriaDeDados::MemoriaDeDados(int tamanho) : tamanho (tamanho) {
    dados = new Dado*[tamanho];

    for(int i = 0; i < tamanho; i++)
        dados[i] = NULL;
}

MemoriaDeDados::~MemoriaDeDados(){
    for(int i = 0; i < tamanho; i++)
        delete dados[i];

    delete[] dados;
}

int MemoriaDeDados::getTamanho(){
    return tamanho;
}

Dado* MemoriaDeDados::ler(int posicao){
    if (posicao < 0 || posicao >= tamanho)
        return NULL;

    else 
        return dados[posicao];
}

bool MemoriaDeDados::escrever(int posicao, Dado* d){
    if (posicao >= 0 && posicao < tamanho){
        dados[posicao] = d;
        return true;
    }
    return false;
}

void MemoriaDeDados::imprimir(){
    for (int i = 0; i < tamanho; i++){
        if (dados[i] == NULL)
            cout << i << ": " << "-" << endl;
        
        else
            cout << i << ": " << dados[i]->getValor() << endl;
    }
}