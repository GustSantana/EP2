#include "UnidadeDeControle.h"

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria) :
                                    registradores(registradores), memoria(memoria){
    PC = 0;
}

UnidadeDeControle::~UnidadeDeControle(){
    delete registradores;
    delete memoria;
}

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores(){
    return registradores;
}

Memoria* UnidadeDeControle::getMemoria(){
    return memorias;
}

int UnidadeDeControle::getPC(){
    return PC;
}

void UnidadeDeControle::setPC(int pc){
    PC = pc;
}

void UnidadeDeControle::executarInstrucao(){
    if (instrucoes->ler(PC) == NULL)
        PC++;
        return;

    int verificaOP = instrucoes->ler(PC)->getOpcode();

    if (verificaOP == TIPO_R){
            if(instrucoes->ler(PC)->getFuncao() == FUNCAO_ADD)
                registradores->setValor(instrucoes->ler(PC)->getDestino(), registradores->getValor(instrucoes->ler(PC)->getOrigem1()) + registradores->getValor(instrucoes->ler(PC)->getOrigem2()));
                return;

            if(instrucoes->ler(PC)->getFuncao() == FUNCAO_SUB)
                registradores->setValor(instrucoes->ler(PC)->getDestino(), registradores->getValor(instrucoes->ler(PC)->getOrigem1()) - registradores->getValor(instrucoes->ler(PC)->getOrigem2()));
                return;

            if(instrucoes->ler(PC)->getFuncao() == FUNCAO_MULT)
                registradores->setValor(24, registradores->getValor(instrucoes->ler(PC)->getOrigem1()) * registradores->getValor(instrucoes->ler(PC)->getOrigem2()));
                return;

            if(instrucoes->ler(PC)->getFuncao() == FUNCAO_DIV){
                registradores->setValor(24, registradores->getValor(instrucoes->ler(PC)->getOrigem1()) / registradores->getValor(instrucoes->ler(PC)->getOrigem2()));
                registradores->setValor(25, registradores->getValor(instrucoes->ler(PC)->getOrigem1()) % registradores->getValor(instrucoes->ler(PC)->getOrigem2()));
                return;
            }
        PC++;
    }


    if (verificaOP == LW) {
        if(dados->ler(instrucoes->ler(PC)->getImediato()) == NULL)
            registradores->setValor(instrucoes->ler(PC)->getDestino(), 0);

        else
            registradores->setValor(instrucoes->ler(PC)->getDestino(), dados->ler(instrucoes->ler(PC)->getImediato())->getValor());  
        PC++;
    }


    if (verificaOP == SW) {
        Dado* dado = new Dado(registradores->getValor(instrucoes->ler(PC)->getDestino()));
        dados->escrever(instrucoes->ler(PC)->getImediato(), dado); 
        PC++;
    }


    if (verificaOP == BNE) {
        if(registradores->getValor(instrucoes->ler(PC)->getOrigem1()) != registradores->getValor(instrucoes->ler(PC)->getOrigem2()))
            PC = registradores->getValor(instrucoes->ler(PC)->getImediato());
        else
            PC++;
    }


    if (verificaOP == BEQ) {
        if(registradores->getValor(instrucoes->ler(PC)->getOrigem1()) == registradores->getValor(instrucoes->ler(PC)->getOrigem2()))
            PC = registradores->getValor(instrucoes->ler(PC)->getImediato()); 
        else
            PC++;
    }


    if (verificaOP == J){
        PC = registradores->getValor(instrucoes->ler(PC)->getImediato()); 
    }

  if((verificaOP != TIPO_R) && (verificaOP != LW) && (verificaOP != SW) && (verificaOP != BNE) && (verificaOP != BEQ) && (verificaOP != J) && (instrucoes->ler(PC) != NULL))
        PC++;
}