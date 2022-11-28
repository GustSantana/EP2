#include "Instrucao.h"
#include <iostream> 

Instrucao::Instrucao(int opcode, int origem1, int origem2, int destino, int imediato, int funcao) : Dado (opcode), 
                    origem1 (origem1), origem2 (origem2), destino (destino), imediato (imediato), funcao(funcao){
}

Instrucao::~Instrucao(){

}

Instrucao* criarLW(int destino, int imediato){
    if(imediato == NULL)
        registradores->setValor(destino, 0);
    else
        registradores->setValor(destino, imediato);  
    PC++; 
}

Instrucao* criarSW(int destino, int imediato){
    Dado* dado = new Dado(registradores->getValor(destino));
    dados->escrever(imediato, dado); 
    PC++;
}
    
Instrucao* criarJ(int imediato){
    PC = registradores->getValor(imediato); 
}

Instrucao* criarBNE(int origem1, int origem2, int imediato){
    if(registradores->getValor(origem1) != registradores->getValor(origem2))
        PC = registradores->getValor(imediato);
    else
        PC++;
}

Instrucao* criarBEQ(int origem1, int origem2, int imediato){
    if(registradores->getValor(instrucoes->ler(PC)->getOrigem1()) == registradores->getValor(instrucoes->ler(PC)->getOrigem2()))
        PC = registradores->getValor(instrucoes->ler(PC)->getImediato()); 
    else
        PC++;
}

Instrucao* criarADD(int destino, int origem1, int origem2){
    registradores->setValor(instrucoes->ler(PC)->getDestino(), registradores->getValor(instrucoes->ler(PC)->getOrigem1()) + registradores->getValor(instrucoes->ler(PC)->getOrigem2()));
    return;
}

Instrucao* criarSUB(int destino, int origem1, int origem2){
    registradores->setValor(destino, registradores->getValor(origem1) - registradores->getValor(origem2));
    return;
}

Instrucao* criarMULT(int origem1, int origem2){
    registradores->setValor(24, registradores->getValor(origem1) * registradores->getValor(origem2));
    return;
}

Instrucao* criarDIV(int origem1, int origem2){
    registradores->setValor(24, registradores->getValor(origem1) / registradores->getValor(origem2));
    registradores->setValor(25, registradores->getValor(origem1) % registradores->getValor(origem2));
    return;
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

void Instrucao::imprimir(){
    cout << 'Instrucao' << opcode; 
}