#include "Instrucao.h"
#include <iostream> 

Instrucao::Instrucao(int opcode, int origem1, int origem2, int destino, int imediato, int funcao) : opcode (opcode), 
                    origem1 (origem1), origem2 (origem2), destino (destino), imediato (imediato), funcao(funcao){
}

Instrucao::~Instrucao(){
}

int Instrucao::getOpcode(){
    return opcode;
}

int Instrucao::getOrigem1(){
    return origem1;
}

int Instrucao::getOrigem2(){
    return origem2;
}

int Instrucao::getDestino(){
    return destino;
}

int Instrucao::getImediato(){
    return imediato;
}

int Instrucao::getFuncao(){
    return funcao;
}