#include "Teclado.h"
#include "Monitor.h"
#include "MemoriaRAM.h"
#include "TecladoDeChar.h"
#include "MonitorDeChar.h"
#include "ESMapeadaNaMemoria.h"
#include "UnidadeDeControle.h"
#include "GerenciadorDeMemoria.h"
#include <iostream>

using namespace std;

int main(){

BancoDeRegistradores *registradores = new BancoDeRegistradores();
MemoriaRAM *memoriaRam = new MemoriaRAM(64);
ESMapeadaNaMemoria *mapmemoria = new ESMapeadaNaMemoria(memoriaRam);
Teclado *teclado = new Teclado;
TecladoDeChar *tecladodechar = new TecladoDeChar;
Monitor *monitor = new Monitor;
MonitorDeChar *monitordechar = new MonitorDeChar;

mapmemoria->adicionar(teclado);
mapmemoria->adicionar(tecladodechar);
mapmemoria->adicionar(monitor);
mapmemoria->adicionar(monitordechar);

UnidadeDeControle *controle = new UnidadeDeControle(registradores, mapmemoria);

Dado* dadoMain;

int escolha = -1;
int escolhido;
int escolhaMemoria;
int escolhaRegistradores;
int memoriaPosicao;
int memoriaValor;
int registradoresPosicao;
int registradoresValor;
string arquivoOrigem;
string arquivoDestino;

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
            cin >> memoriaPosicao;
            cout << "Novo valor: ";
            cin >> memoriaValor;
            cout << endl;

            dadoMain = new Dado(memoriaValor);
            memoriaRam->escrever(memoriaPosicao, dadoMain);
        }

        if(escolhaMemoria == 2){
            memoriaRam->imprimir();
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
        cin >> escolhaRegistradores;
        cout << endl;

        if(escolhaRegistradores == 1){
            cout << "Posicao a ser alterada: ";
            cin >> registradoresPosicao;
            cout << "Novo valor: ";
            cin >> registradoresValor;
            cout << endl;

            registradores->setValor(registradoresPosicao, registradoresValor);
        }

        if(escolhaRegistradores == 2){
            registradores->imprimir();
        }
        
        if (escolhaRegistradores == 0) {
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

    if(escolhido == 4){
        while(controle->getPC() != 0)
            controle->executarInstrucao();
    }
    
    if(escolhido == 5){
        cout << "Arquivo origem: ";
        cin >> arquivoOrigem;
        try{
        GerenciadorDeMemoria* gerenciaMemoria = new GerenciadorDeMemoria();
        gerenciaMemoria->load(arquivoOrigem, memoriaRam);
        } catch (runtime_error *e){
            cout << e->what();
            delete e;
        }
    }

    if(escolhido == 6){
        cout << "Arquivo destino: ";
        cin >> arquivoDestino;
        try{
        GerenciadorDeMemoria* gerenciaMemoria = new GerenciadorDeMemoria();
        gerenciaMemoria->dump(arquivoDestino, memoriaRam);
        } catch (runtime_error *e){
            cout << e->what();
            delete e;
    }

    if(escolhido == 0){
        delete controle;
        return 0;
    }
}
}