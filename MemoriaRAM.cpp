#include "MemoriaRAM.h"

MemoriaRam::MemoriaRam(int tamanho) : tamanho(tamanho){
    this->vetorDados = new Dado*[tamanho];
    for (int i = 0; i < tamanho; i++)
        vetorDados[i] = NULL;
}

MemoriaRam::~MemoriaRam() {
    for (int i = 0; i < tamanho; i++)
        delete vetorDados[i];
    delete[] vetorDados;
}

int MemoriaRam::getTamanho(){
    return this->tamanho;
}

Dado* MemoriaRam::ler(int posicao) {
    if (posicao < 0 || posicao >= tamanho)
        throw new logic_error("logic_error");

    else 
        return vetorDados[posicao];
}

void MemoriaRam::escrever(int posicao, Dado* d){
    if (posicao < 0 || posicao >= tamanho)
        throw new logic_error("logic_error");

    else if (vetorDados[posicao] != NULL)
        delete vetorDados[posicao];
    
    vetorDados[posicao] = d;
}

void MemoriaRam::escrever(list<Dado*>* dados){
    if (dados->size() > this->tamanho)
        throw new logic_error("logic_error");

    list<Dado*>::iterator i = dados->begin();
    int j = 0;
    while(i != dados->end()){
        vetorDados[j] = *i;
        j++;
        i++;
    }
}

void MemoriaRam::imprimir(){
    for (int i = 0; i < tamanho; i++){
        if (vetorDados[i] == NULL)
            cout << i << ": " << "-" << endl;
        
        else
            cout << i << ": " << vetorDados[i]->imprimir() << endl;
    }
}

