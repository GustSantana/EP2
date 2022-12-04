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

    list<Dado*>* listaDeDados;
    Dado* dado;

    ler >> tamanho;
    if(tamanho > m->getTamanho())
        throw new runtime_error("runtime_error");

    ler >> tipo;
    while(ler){
        if(tipo == "D"){
            ler >> valor;
            dado = new Dado(valor);
            listaDeDados->push_back(dado);
        }
        else{
            if(tipo == "LW"){
                ler >> valor >> valor2;
                listaDeDados->push_back(Instrucao::criarLW(valor, valor2));
            }
            if(tipo == "SW"){
                ler >> valor >> valor2;
                listaDeDados->push_back(Instrucao::criarSW(valor, valor2));
            }
            if(tipo == "J"){
                ler >> valor;
                listaDeDados->push_back(Instrucao::criarJ(valor));
            }
            if(tipo == "BNE"){
                ler >> valor >> valor2 >> valor3;
                listaDeDados->push_back(Instrucao::criarBNE(valor, valor2, valor3));
            }
            if(tipo == "BEQ"){
                ler >> valor >> valor2 >> valor3;
                listaDeDados->push_back(Instrucao::criarBEQ(valor, valor2, valor3));
            }
            if(tipo == "ADD"){
                ler >> valor >> valor2 >> valor3;
                listaDeDados->push_back(Instrucao::criarADD(valor, valor2, valor3));
            }
            if(tipo =="SUB"){
                ler >> valor >> valor2 >> valor3;
                listaDeDados->push_back(Instrucao::criarSUB(valor, valor2, valor3));
            }
            if(tipo == "MULT"){
                ler >> valor >> valor2;
                listaDeDados->push_back(Instrucao::criarMULT(valor, valor2));
            }
            if(tipo == "DIV"){
                ler >> valor >> valor2;
                listaDeDados->push_back(Instrucao::criarDIV(valor, valor2));            
            }
            if(tipo == "-"){
                listaDeDados->push_back(NULL);
            }
        }
        posicao++;
        ler >> tipo;
    }

    if(!ler.eof()){
         throw new logic_error ("logic_error");
         ler.close();
    }

    m->escrever(listaDeDados);

    ler.close();
}

void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM* m){
    ofstream escrever;
    escrever.open (arquivo, ios_base::app);

    Instrucao *instrucao;
    for(int i = 0; i < m->getTamanho(); i++){
        if(m->ler(i) == NULL)
            escrever << "-" << endl;
        
        instrucao = dynamic_cast<Instrucao*>(m->ler(i));
        if(instrucao == NULL)
            escrever << "D " << m->ler(i)->getValor() << endl;
        else{
            if(instrucao->getOpcode() == Instrucao::LW){
                escrever << "LW " << instrucao->getDestino() << " " << instrucao->getImediato() << endl;
            }
            if(instrucao->getOpcode() == Instrucao::SW){
                escrever << "SW " << instrucao->getDestino() << " " << instrucao->getImediato() <<  endl;
            }

            if(instrucao->getOpcode() == Instrucao::J){
                escrever << "J " << instrucao->getImediato() << endl;
            }

            if(instrucao->getOpcode() == Instrucao::BNE){
                escrever << "BNE " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << " " << instrucao->getImediato() << endl;
            }

            if(instrucao->getOpcode() == Instrucao::BEQ){
                escrever << "BEQ " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << " " << instrucao->getImediato() << endl;
            }

            if(instrucao->getOpcode() == Instrucao::TIPO_R){
                if(instrucao->getFuncao() == Instrucao::FUNCAO_ADD){
                    escrever << "ADD " << instrucao->getDestino() << " " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                }

                if(instrucao->getFuncao() == Instrucao::FUNCAO_SUB){
                    escrever << "SUB " << instrucao->getDestino() << " " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                }

                if(instrucao->getFuncao() == Instrucao::FUNCAO_MULT){
                    escrever << "MULT " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                }

                if(instrucao->getFuncao() == Instrucao::FUNCAO_DIV){
                   escrever << "DIV " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                }
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