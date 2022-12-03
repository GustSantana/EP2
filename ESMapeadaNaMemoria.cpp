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