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

}