#ifndef ES_MAPEADA_NA_MEMORIA_H
#define ES_MAPEADA_NA_MEMORIA_H

#include "Memoria.h"
#include "MemoriaRAM.h"
#include "Dispositivo.h"
#include <vector>

using namespace std;

class ESMapeadaNaMemoria : public Memoria{
    private:
        MemoriaRAM* m;
        vector<Dispositivo*>* dispositivos;

    public:
        ESMapeadaNaMemoria(MemoriaRAM* m);
        ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos);
        virtual ~ESMapeadaNaMemoria();

        virtual MemoriaRAM* getMemoriaSubjacente();
        virtual void adicionar(Dispositivo* d);
        virtual vector<Dispositivo*>* getDispositivos();
};

#endif // ES_MAPEADA_NA_MEMORIA_H