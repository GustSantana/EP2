#include "Instrucao.h"
#include <iostream> 

Instrucao::Instrucao(int opcode, int origem1, int origem2, int destino, int imediato, int funcao) : Dado (opcode), 
                    origem1 (origem1), origem2 (origem2), destino (destino), imediato (imediato), funcao(funcao){
}

Instrucao::~Instrucao(){
}
/*
Instrucao* criarLW(int destino, int imediato){
}

Instrucao* criarSW(int destino, int imediato){
}
    
Instrucao* criarJ(int imediato){ 
}
Instrucao* criarBNE(int origem1, int origem2, int imediato){
}

Instrucao* criarBEQ(int origem1, int origem2, int imediato){
}

Instrucao* criarADD(int destino, int origem1, int origem2){
}

Instrucao* criarSUB(int destino, int origem1, int origem2){
}

Instrucao* criarMULT(int origem1, int origem2){
}

Instrucao* criarDIV(int origem1, int origem2){
}
*/
int Instrucao::getOpcode(){
    return getValor();
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
/*
void Instrucao::imprimir(){
    cout << 'Instrucao' << opcode; 
}
*/