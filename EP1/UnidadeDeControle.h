#ifndef UNIDADE_CONTROLE_H
#define UNIDADE_CONTROLE_H

#include "BancoDeRegistradores.h"
#include "MemoriaDeDados.h"
#include "MemoriaDeInstrucoes.h"

using namespace std;

class UnidadeDeControle{
private:
    BancoDeRegistradores* registradores;
    MemoriaDeInstrucoes* instrucoes;
    MemoriaDeDados* dados;
    int PC;

public:
    UnidadeDeControle(BancoDeRegistradores* registradores, MemoriaDeInstrucoes* instrucoes, MemoriaDeDados* dados);
    virtual ~UnidadeDeControle();
    BancoDeRegistradores* getBancoDeRegistradores();
    MemoriaDeDados* getMemoriaDeDados();
    MemoriaDeInstrucoes* getMemoriaDeInstrucoes();
    int getPC();
    void setPC(int pc);
    void executarInstrucao();

};

#endif // UNIDADE_CONTROLE_H