#ifndef MOTORHIBRID_H
#define MOTORHIBRID_H

#include "motor.h"
#include "motorElectric.h"
#include "motorCombustibil.h"

class motorHibrid : public motorElectric, public motorCombustibil {
public:
    motorHibrid(int caiPutere = 0, int cuplu = 0, string tipCombustibil = "Blank", int nivel_rezervor = 100, int baterie = 100);
    motorHibrid(const motorHibrid& m);
    ~motorHibrid();

    void afisare(ostream& out) const;
    void citire(istream& in);
    void generare_motor();
    void consuma_resurse();
    
    void reseteaza();
    bool verifica_resurse();

    motorHibrid* creeaza_motor() const;
};

#endif