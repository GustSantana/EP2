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
    return memoria;
}

int UnidadeDeControle::getPC(){
    return PC;
}

void UnidadeDeControle::setPC(int pc){
    PC = pc;
}

void UnidadeDeControle::executarInstrucao(){
    Instrucao *instrucao = dynamic_cast<Instrucao*>(memoria->ler(PC));
    
    if (instrucao == NULL)
        PC++;
        return;

    int verificaOP = instrucao->getOpcode();

    if (verificaOP == Instrucao::TIPO_R){
            if(instrucao->getFuncao() == Instrucao::FUNCAO_ADD)
                registradores->setValor(instrucao->getDestino(), registradores->getValor(instrucao->getOrigem1()) + registradores->getValor(instrucao->getOrigem2()));
                return;

            if(instrucao->getFuncao() == Instrucao::FUNCAO_SUB)
                registradores->setValor(instrucao->getDestino(), registradores->getValor(instrucao->getOrigem1()) - registradores->getValor(instrucao->getOrigem2()));
                return;

            if(instrucao->getFuncao() == Instrucao::FUNCAO_MULT)
                registradores->setValor(24, registradores->getValor(instrucao->getOrigem1()) * registradores->getValor(instrucao->getOrigem2()));
                return;

            if(instrucao->getFuncao() == Instrucao::FUNCAO_DIV){
                registradores->setValor(24, registradores->getValor(instrucao->getOrigem1()) / registradores->getValor(instrucao->getOrigem2()));
                registradores->setValor(25, registradores->getValor(instrucao->getOrigem1()) % registradores->getValor(instrucao->getOrigem2()));
                return;
            }
        PC++;
    }


    if (verificaOP == Instrucao::LW) {
        if(memoria->ler(instrucao->getImediato()) == NULL)
            registradores->setValor(instrucao->getDestino(), 0);

        else
            registradores->setValor(instrucao->getDestino(), memoria->ler(instrucao->getImediato())->getValor());  
        PC++;
    }


    if (verificaOP == Instrucao::SW) {
        Dado* dado = new Dado(registradores->getValor(instrucao->getDestino()));
        memoria->escrever(instrucao->getImediato(), dado);
        PC++;
    }


    if (verificaOP == Instrucao::BNE) {
        if(registradores->getValor(instrucao->getOrigem1()) != registradores->getValor(instrucao->getOrigem2()))
            PC = registradores->getValor(instrucao->getImediato());
        else
            PC++;
    }


    if (verificaOP == Instrucao::BEQ) {
        if(registradores->getValor(instrucao->getOrigem1()) == registradores->getValor(instrucao->getOrigem2()))
            PC = registradores->getValor(instrucao->getImediato()); 
        else
            PC++;
    }


    if (verificaOP == Instrucao::J){
        PC = registradores->getValor(instrucao->getImediato()); 
    }

  if((verificaOP != Instrucao::TIPO_R) &&
  (verificaOP != Instrucao::LW) && 
  (verificaOP != Instrucao::SW) && 
  (verificaOP != Instrucao::BNE) && 
  (verificaOP != Instrucao::BEQ) && 
  (verificaOP != Instrucao::J) && 
  (instrucao != NULL))
        PC++;
}