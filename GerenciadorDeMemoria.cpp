#include "GerenciadorDeMemoria.h"

GerenciadorDeMemoria::GerenciadorDeMemoria(){
}

GerenciadorDeMemoria::~GerenciadorDeMemoria(){
}

void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM* m){
    ifstream ler;
    ler.open(arquivo);

    if (ler.fail()){
        throw new runtime_error ("runtime_error");
    }

    int tamanho, valor, valor2, valor3, posicao = 0;
    string tipo;

    ler >> tamanho;
    ler >> tipo >> valor;
    while(ler){
        if(tipo == "D"){
            Dado* dado = new Dado(valor);
            m->escrever(posicao, dado);
        }
        else{
            if(tipo == "LW"){
                Dado* dado = new Dado(Instrucao::LW);
                m->escrever(posicao, dado);
            }
            if(tipo == "SW"){
                Dado* dado = new Dado(Instrucao::SW);
                m->escrever(posicao, dado);
            }
            if(tipo == "J"){
                Dado* dado = new Dado(Instrucao::J);
                m->escrever(posicao, dado);
            }
            if(tipo == "BNE"){
                Dado* dado = new Dado(Instrucao::BNE);
                m->escrever(posicao, dado);
            }
            if(tipo == "BEQ"){
                Dado* dado = new Dado(Instrucao::BEQ);
                m->escrever(posicao, dado);
            }
            if(tipo == "ADD" || tipo =="SUB" || tipo == "MULT" || tipo == "DIV"){
                Dado* dado = new Dado(Instrucao::TIPO_R);
                m->escrever(posicao, dado);
            }
        }
        posicao++;
        ler >> tipo >> valor;
    }

    if(!ler.eof()){
         throw new logic_error ("logic_error");
         ler.close();
    }

    ler.close();
}

void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM* m){
    ofstream escrever;
    escrever.open (arquivo, ios_base::app);
    for(int i = 0; i < m->getTamanho(); i++){
        if(m->ler(i) == NULL)
            escrever << "-" << endl;

        Instrucao *instrucao = dynamic_cast<Instrucao*>(m->ler(i));
        if(instrucao == NULL)
            escrever << "D " << m->ler(i)->getValor() << endl;
        else{
            if(instrucao->getOpcode() == Instrucao::LW)
                escrever << "LW " << instrucao->getDestino() << " " << instrucao->getImediato() << endl;

            if(instrucao->getOpcode() == Instrucao::SW)
                escrever << "SW " << instrucao->getDestino() << " " << instrucao->getImediato() <<  endl;

            if(instrucao->getOpcode() == Instrucao::J)
                escrever << "J " << instrucao->getImediato() << endl;
            
            if(instrucao->getOpcode() == Instrucao::BNE)
                escrever << "BNE " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << " " << instrucao->getImediato() << endl;
            
            if(instrucao->getOpcode() == Instrucao::BEQ)
                escrever << "BEQ " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << " " << instrucao->getImediato() << endl;
            
            if(instrucao->getOpcode() == Instrucao::TIPO_R){
                if(instrucao->getFuncao() == Instrucao::FUNCAO_ADD)
                    escrever << "ADD " << instrucao->getDestino() << " " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                
                if(instrucao->getFuncao() == Instrucao::FUNCAO_SUB)
                    escrever << "SUB " << instrucao->getDestino() << " " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                
                if(instrucao->getFuncao() == Instrucao::FUNCAO_MULT)
                    escrever << "MULT " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;

                if(instrucao->getFuncao() == Instrucao::FUNCAO_DIV)
                    escrever << "DIV " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
            }
            if(escrever.fail())
                throw new runtime_error ("runtime_error");
            
            int verificaOP = instrucao->getOpcode();
            if((verificaOP != Instrucao::TIPO_R) && (verificaOP != Instrucao::LW) && (verificaOP != Instrucao::SW) && 
            (verificaOP != Instrucao::BNE) && (verificaOP != Instrucao::BEQ) && (verificaOP != Instrucao::J) && (instrucao != NULL))
                throw new runtime_error ("runtime_error");
        }
    }
}