#include "BancoDeRegistradores.h"
#include <stdexcept>
#include <iostream>

BancoDeRegistradores::BancoDeRegistradores(){
    registrador = new int[QUANTIDADE_REGISTRADORES];
    for(int i = 0; i < QUANTIDADE_REGISTRADORES; i++){
        registrador[i] = 0;
    }
}

BancoDeRegistradores::~BancoDeRegistradores(){
    delete[] registrador;
}

int BancoDeRegistradores::getValor(int registrador){
    if(registrador == 0){
        return 0;
    }

    else if (registrador < 0 || registrador >= 32){
        throw new logic_error("logic_error");
    }
        
    else {
        return this->registrador[registrador];
    }
}

void BancoDeRegistradores::setValor(int registrador, int valor){
    if (registrador < 0 || registrador >= 32){
        throw new logic_error("logic_error");
    }

    else {
        this->registrador[registrador] = valor;
    }       
}

void BancoDeRegistradores::imprimir(){
    for(int i = 0; i < QUANTIDADE_REGISTRADORES; i++)
        cout << i << ": " << this->registrador[i] << endl;
    cout << endl;
}