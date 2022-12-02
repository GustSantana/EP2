#include "Monitor.h"

Monitor::Monitor(){
}

Monitor::~Monitor(){
}

Dado* Monitor::ler(){
    throw new logic_error("logic_error");
}

void Monitor::escrever(Dado* d){
    cout << d;
}