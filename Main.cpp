#include "Teclado.h"
#include "Monitor.h"
#include "MemoriaRAM.h"
#include "TecladoDeChar.h"
#include "MonitorDeChar.h"
#include "ESMapeadaNaMemoria.h"
#include "UnidadeDeControle.h"
#include <iostream>

using namespace std;

int main(){

BancoDeRegistradores *registradores = new BancoDeRegistradores();
MemoriaRAM *memoriaRam = new MemoriaRAM(64);
ESMapeadaNaMemoria *esmapeadanamemoria = new ESMapeadaNaMemoria(memoriaRam);
Teclado *teclado = new Teclado;
TecladoDeChar *tecladodechar = new TecladoDeChar;
Monitor *monitor = new Monitor;
MonitorDeChar *monitordechar = new MonitorDeChar;
esmapeadanamemoria->adicionar(teclado);
esmapeadanamemoria->adicionar(tecladodechar);
esmapeadanamemoria->adicionar(monitor);
esmapeadanamemoria->adicionar(monitordechar);
UnidadeDeControle *unidadecontrole = new UnidadeDeControle(registradores, esmapeadanamemoria);



Dado* dadoMain;

int escolha = -1;
int escolhido;
int escolhaMemoria;
int escolhaRegistradores;
int dadoPosicao;
int dadoValor;
int registradorPosicao;
int registradorValor;

// Instrucao* instrucao1 = new Instrucao(LW, -1, -1, 8, 0, -1);
// Instrucao* instrucao2 = new Instrucao(LW, -1, -1, 9, 1, -1);
// Instrucao* instrucao3 = new Instrucao(LW, -1, -1, 10, 2, -1);
// Instrucao* instrucao4 = new Instrucao(BNE, 9, 10, -1, 7, -1);
// Instrucao* instrucao5 = new Instrucao(TIPO_R, 8, 10, -1, -1, FUNCAO_MULT);
// Instrucao* instrucao6 = new Instrucao(SW, -1, -1, 24, 3, -1);
// Instrucao* instrucao7 = new Instrucao(J, -1, -1, -1, 0, -1);
// Instrucao* instrucao8 = new Instrucao(TIPO_R, 10, 8, 9, -1, FUNCAO_ADD);
// Instrucao* instrucao9 = new Instrucao(SW, -1, -1, 9, 3, -1);
// Instrucao* instrucao10 = new Instrucao(J, -1, -1, -1, 10, -1);

// instrucoes->escrever(0, instrucao1);
// instrucoes->escrever(1, instrucao2);
// instrucoes->escrever(2, instrucao3);
// instrucoes->escrever(3, instrucao4);
// instrucoes->escrever(4, instrucao5);
// instrucoes->escrever(5, instrucao6);
// instrucoes->escrever(6, instrucao7);
// instrucoes->escrever(7, instrucao8);
// instrucoes->escrever(8, instrucao9);
// instrucoes->escrever(9, instrucao10);

while(escolha == -1) {
    cout << "Emulador de MIPS" << endl;
    cout << "1) Memoria de Dados" << endl;
    cout << "2) Registradores" << endl;
    cout << "3) Executar proxima instrucao" << endl;
    cout << "4) Executar ate PC = 0" << endl;
    cout << "5) Load" << endl;
    cout << "6) Dump" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opcao: "; 
    cin >> escolhido;
    cout << endl;


    while(escolhido == 1) {
        cout << "Memoria" << endl;
        cout << "1) Alterar dado" << endl;
        cout << "2) Imprimir" << endl;
        cout << "0) Voltar" << endl;
        cout << "Escolha uma opcao: "; 
        cin >> escolhaMemoria;
        cout << endl;

        if(escolhaMemoria == 1){
            cout << "Posicao a ser alterada: ";
            cin >> dadoPosicao;
            cout << "Novo valor: ";
            cin >> dadoValor;
            cout << endl;

            dadoMain = new Dado(dadoValor);
            dados->escrever(dadoPosicao, dadoMain);
        }

        if(escolhaMemoria == 2){
            dados->imprimir();
        }

        if (escolhaMemoria == 0){
            break;
        }
    }
    while(escolhido == 2) {
        cout << "Registradores" << endl;
        cout << "1) Alterar valor" << endl;
        cout << "2) Imprimir" << endl;
        cout << "0) Voltar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolhaRegistrador;
        cout << endl;

        if(escolhaRegistrador == 1){
            cout << "Posicao a ser alterada: ";
            cin >> registradorPosicao;
            cout << "Novo valor: ";
            cin >> registradorValor;
            cout << endl;

            registradores->setValor(registradorPosicao, registradorValor);
        }

        if(escolhaRegistrador == 2){
            registradores->imprimir();
        }
        
        if (escolhaRegistrador == 0) {
            break;
        }
    }

    if(escolhido == 3){
        cout << "PC: " << controle->getPC() << endl;
        controle->executarInstrucao();
        cout << "Instrucao executada" << endl;
        cout << "PC: " << controle->getPC()<< endl;
        cout << endl;
    }

    if(escolhido == 0){
        delete controle;
        return 0;
    }
    
}
}