#include "GerenciadorDeMemoria.h"

GerenciadorDeMemoria::GerenciadorDeMemoria(){
}

GerenciadorDeMemoria::~GerenciadorDeMemoria(){
}

void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM *m)
{
    ifstream ler;
    ler.open(arquivo);

    if (ler.fail()){
        throw new runtime_error("runtime_error");
    }

    string tipo;
    int posicao = 0, tamanho;
    int imediato, destino, origem1, origem2;
    int valor;

    ler >> tamanho;
    if (tamanho > m->getTamanho())
        throw new runtime_error("runtime_error");

    while (ler && posicao < m->getTamanho())
    {
        ler >> tipo;
        if (tipo == "D"){
            ler >> valor;
            Dado *dado = new Dado(valor);
            m->escrever(posicao++, dado);
            continue;
        }
        else{
            if (tipo == "LW"){
                ler >> destino;
                ler >> imediato;
                m->escrever(posicao++, Instrucao::criarLW(destino, imediato));
                continue;
            }
            if (tipo == "SW"){
                ler >> destino;
                ler >> imediato;
                m->escrever(posicao++, Instrucao::criarSW(destino, imediato));
                continue;
            }
            if (tipo == "J"){
                ler >> imediato;
                m->escrever(posicao++, Instrucao::criarJ(imediato));
                continue;
            }
            if (tipo == "BNE"){
                ler >> origem1;
                ler >> origem2;
                ler >> imediato;
                m->escrever(posicao++, Instrucao::criarBNE(origem1, origem2, imediato));
                continue;
            }
            if (tipo == "BEQ"){
                ler >> origem1;
                ler >> origem2;
                ler >> imediato;
                m->escrever(posicao++, Instrucao::criarBEQ(origem1, origem2, imediato));
                continue;
            }
            if (tipo == "ADD"){
                ler >> destino;
                ler >> origem1;
                ler >> origem2;
                m->escrever(posicao++, Instrucao::criarADD(destino, origem1, origem2));
                continue;
            }
            if (tipo == "SUB"){
                ler >> destino;
                ler >> origem1;
                ler >> origem2;
                m->escrever(posicao++, Instrucao::criarSUB(destino, origem1, origem2));
                continue;
            }
            if (tipo == "MULT"){
                ler >> origem1;
                ler >> origem2;
                m->escrever(posicao++, Instrucao::criarMULT(origem1, origem2));
                continue;
            }
            if (tipo == "DIV"){
                ler >> origem1;
                ler >> origem2;
                m->escrever(posicao++, Instrucao::criarDIV(origem1, origem2));
                continue;
            }
            if (tipo == "-"){
                m->escrever(posicao++, NULL);
                continue;
            }
        }
    }
    ler.close();
}

void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM *m)
{
    ofstream escrever;
    escrever.open (arquivo, ios_base::app);

    if (escrever.fail())
        throw new runtime_error("runtime_error");

    else
        escrever << m->getTamanho() << endl;

    for (int i = 0; i < m->getTamanho(); i++){

        Instrucao *instrucao = dynamic_cast<Instrucao *>(m->ler(i));

        if (m->ler(i) == NULL){
            escrever << "-" << endl;
            continue;
        }

        if(instrucao == NULL)
            escrever << "D " << m->ler(i)->getValor() << endl;

        else{
            if (instrucao->getOpcode() == Instrucao::J){
                escrever << "J " << instrucao->getImediato() << endl;
                continue;
            }

            if (instrucao->getOpcode() == Instrucao::BNE){
                escrever << "BNE " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << " " << instrucao->getImediato() << endl;
                continue;
            }

            if (instrucao->getOpcode() == Instrucao::BEQ){
                escrever << "BEQ " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << " " << instrucao->getImediato() << endl;
                continue;
            }

            if (instrucao->getOpcode() == Instrucao::SW){
                escrever << "SW " << instrucao->getDestino() << " " << instrucao->getImediato() << endl;
                continue;
            }

            if (instrucao->getOpcode() == Instrucao::LW){
                escrever << "LW " << instrucao->getDestino() << " " << instrucao->getImediato() << endl;
                continue;
            }

            if (instrucao->getOpcode() == 0){
                if (instrucao->getFuncao() == Instrucao::FUNCAO_ADD){
                    escrever << "ADD " << instrucao->getDestino() << " " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                    continue;
                }
                if (instrucao->getFuncao() == Instrucao::FUNCAO_SUB){
                    escrever << "SUB " <<instrucao->getDestino() << " " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                    continue;
                }

                if (instrucao->getFuncao() == Instrucao::FUNCAO_MULT){
                    escrever << "MULT " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                    continue;
                }

                if (instrucao->getFuncao() == Instrucao::FUNCAO_DIV){
                    escrever << "DIV " << instrucao->getOrigem1() << " " << instrucao->getOrigem2() << endl;
                    continue;
                }
            }
        }
        
    }
}