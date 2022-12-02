#include "Teclado.h"

Teclado::Teclado(){
}

Teclado::~Teclado(){
}

Dado* Teclado::ler(){
    cout << "Digite um numero: ";
    cin >> numero;
    Dado *d1 = new Dado(numero);
    return d1;
}

void Teclado::escrever(Dado* d){
    throw new logic_error("logic_error");
}