#ifndef MOTORCOMBUSTIBIL_H
#define MOTORCOMBUSTIBIL_H

#include "motor.h"

class motorCombustibil : virtual public motor{
protected:
    string tipCombustibil;
    int nivel_rezervor;

public:
    motorCombustibil(int caiPutere = 0, int cuplu = 0, string tipCombustibil = "blank", int nivel_rezervor = 100);
    motorCombustibil(const motorCombustibil& m);
    ~motorCombustibil();

    void afisare(ostream& out) const;
    void citire(istream& in);
    void generare_motor();
    void consuma_resurse();
    int getCai(){
        return this->caiPutere;
    }
    void reseteaza();
    bool verifica_resurse();

    motorCombustibil* creeaza_motor() const;
};

#endif