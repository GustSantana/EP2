#include "Instrucao.h"

Instrucao::Instrucao(int opcode, int origem1, int origem2, int destino, int imediato, int funcao) : Dado (opcode), 
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

Instrucao* Instrucao::criarLW(int destino, int imediato){
    Instrucao* criarLW = new Instrucao(LW, 0, 0, destino, imediato, 0);
    return criarLW;
}

Instrucao* Instrucao::criarSW(int destino, int imediato){
    Instrucao* criarSW = new Instrucao(SW, 0, 0, destino, imediato, 0);
    return criarSW;
}
    
Instrucao* Instrucao::criarJ(int imediato){
    Instrucao* criarJ = new Instrucao(J, 0, 0, 0, imediato, 0);
    return criarJ;
}

Instrucao* Instrucao::criarBNE(int origem1, int origem2, int imediato){
    Instrucao* criarBNE = new Instrucao(BNE, origem1, origem2, 0, imediato, 0);
    return criarBNE;
}

Instrucao* Instrucao::criarBEQ(int origem1, int origem2, int imediato){
    Instrucao* criarBEQ = new Instrucao(BEQ, origem1, origem2, 0, imediato, 0);
    return criarBEQ;
}

Instrucao* Instrucao::criarADD(int destino, int origem1, int origem2){
    Instrucao* criarADD = new Instrucao(TIPO_R, origem1, origem2, destino, 0, FUNCAO_ADD);
    return criarADD;
}

Instrucao* Instrucao::criarSUB(int destino, int origem1, int origem2){
    Instrucao* criarSUB = new Instrucao(TIPO_R, origem1, origem2, destino, 0, FUNCAO_SUB);
    return criarSUB;
}

Instrucao* Instrucao::criarMULT(int origem1, int origem2){
    Instrucao* criarMULT = new Instrucao(TIPO_R, origem1, origem2, 0, 0, FUNCAO_MULT);
    return criarMULT;
}

Instrucao* Instrucao::criarDIV(int origem1, int origem2){
    Instrucao* criarDIV = new Instrucao(TIPO_R, origem1, origem2, 0, 0, FUNCAO_DIV);
    return criarDIV;
}

void Instrucao::imprimir(){
    cout << 'Instrucao' << opcode; 
}