#include "ESMapeadaNaMemoria.h"

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m) : m(m) {

}

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos) : m(m), dispositivos(dispositivos) {

}

ESMapeadaNaMemoria::~ESMapeadaNaMemoria(){
    delete m;
    for(unsigned int i = 0; i < dispositivos->size(); i++){
        delete dispositivos->at(i);
    }
}

MemoriaRAM* ESMapeadaNaMemoria::getMemoriaSubjacente(){
    return m;
}

void ESMapeadaNaMemoria::adicionar(Dispositivo* d){
    dispositivos->push_back(d);

}

vector<Dispositivo*>* ESMapeadaNaMemoria::getDispositivos(){
    return dispositivos;
}

int ESMapeadaNaMemoria::getTamanho(){
    return (m->getTamanho() + dispositivos->size());
}

Dado* ESMapeadaNaMemoria::ler(int posicao){
    if(posicao < 0 || posicao > m->getTamanho() + dispositivos->size())
        throw new logic_error("logic_error");
    else{
        if(posicao < m->getTamanho())
            return m->ler(posicao);
        else
            return dispositivos->at(posicao)->ler();
    }
}

void ESMapeadaNaMemoria::escrever(int posicao, Dado* d){
    if(posicao < 0 || posicao > m->getTamanho() + dispositivos->size())
        throw new logic_error("logic_error");
    else{
        if(posicao < m->getTamanho())
            m->escrever(posicao, d);
        else
            dispositivos->at(posicao)->escrever(d);
    }
}

void ESMapeadaNaMemoria::imprimir(){
    m->imprimir();
}