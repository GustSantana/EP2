#include "MonitorDeChar.h"

MonitorDeChar::MonitorDeChar(){

}

MonitorDeChar::~MonitorDeChar(){

}

Dado* MonitorDeChar::ler(){
    throw new logic_error("logic_error");
}

void MonitorDeChar::escrever(Dado* d){
    cout << (char)d;
}