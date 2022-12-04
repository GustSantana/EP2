#include "MemoriaRAM.h"

MemoriaRAM::MemoriaRAM(int tamanho) : tamanho(tamanho){
    this->vetorDados = new Dado*[tamanho];
    for (int i = 0; i < tamanho; i++)
        vetorDados[i] = NULL;
}

MemoriaRAM::~MemoriaRAM() {
    for (int i = 0; i < tamanho; i++)
        delete vetorDados[i];
    delete[] vetorDados;
}

int MemoriaRAM::getTamanho(){
    return this->tamanho;
}

Dado* MemoriaRAM::ler(int posicao) {
    if (posicao < 0 || posicao >= tamanho)
        throw new logic_error("logic_error");

    else 
        return vetorDados[posicao];
}

void MemoriaRAM::escrever(int posicao, Dado* d){
    if (posicao < 0 || posicao >= tamanho)
        throw new logic_error("logic_error");

    else if (vetorDados[posicao] != NULL)
        delete vetorDados[posicao];
    
    vetorDados[posicao] = d;
}

void MemoriaRAM::escrever(list<Dado*>* dados){
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

void MemoriaRAM::imprimir(){
    for (int i = 0; i < tamanho; i++){
        if (vetorDados[i] == NULL)
            cout << i << ": " << "-" << endl;
        
        else{
                cout << i << ": ";
                vetorDados[i]->imprimir();
                cout << endl;
        }
    }
}

