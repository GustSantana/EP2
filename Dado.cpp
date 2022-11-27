#include "Dado.h"
#include <iostream> 

Dado::Dado(int valor) : valor (valor) {
}

Dado::~Dado(){
}

int Dado::getValor() {
    return valor;
}

void Dado::imprimir() {
    cout << valor;
}