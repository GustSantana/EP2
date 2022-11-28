#ifndef TECLADO_H
#define TECLADO_H

#include <string>
#include <iostream> 

using namespace std;

class Teclado {
private:
    int valor;

public:
    Teclado();
    virtual ~Teclado();
};

#endif  // TECLADO_H