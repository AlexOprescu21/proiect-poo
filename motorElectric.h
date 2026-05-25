#ifndef MOTORELECTRIC_H
#define MOTORELECTRIC_H

#include "motor.h"

class motorElectric : virtual public motor{
protected:
    int baterie;
public:
    motorElectric(int caiPutere = 0, int cuplu = 0, int baterie = 100);
    motorElectric(const motorElectric& m);
    ~motorElectric();

    void afisare(ostream& out) const;
    void citire(istream& in);
    void generare_motor();
    void consuma_resurse();
    int getCai(){
        return this->caiPutere;
    }
    int getBaterie(){
        return this->baterie;
    }
    void reseteaza();
    bool verifica_resurse();

    motorElectric* creeaza_motor() const;
};

#endif