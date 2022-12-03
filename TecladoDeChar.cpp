#include "TecladoDeChar.h"

TecladoDeChar::TecladoDeChar(){
}

TecladoDeChar::~TecladoDeChar(){
}

Dado* TecladoDeChar::ler(){
    cout << "Digite um caractere: ";
    cin >> caractere;

    Dado *d1 = new Dado(caractere);
    return d1;
}

void TecladoDeChar::escrever(Dado* d){
    throw new logic_error("logic_error");
}