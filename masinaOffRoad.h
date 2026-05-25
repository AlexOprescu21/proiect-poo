#ifndef MASINAOFFROAD_H
#define MASINAOFFROAD_H

#include "masina.h"

class masinaOffRoad : public masina{
    int tractiune;
    bool diferential;

public:
    masinaOffRoad(string nume = "Blank", motorCombustibil* mot = NULL, int tractiune = 0, bool diferential = 0);
    masinaOffRoad(const masinaOffRoad& m);
    masinaOffRoad& operator=(const masinaOffRoad& m);
    ~masinaOffRoad();

    void calculeaza_distanta(int greutate_circuit);
    void afisare(ostream& out) const;
    void citire(istream& in);
    void afisare_jucator() const;

    void generare_masina();

    void setTractiune(int tractiune){
        this->tractiune = tractiune;
    }
    void setDiferential(bool diferential){
        this->diferential = diferential;
    }

    int getDiferential(){
        return this->diferential;
    }
    void reseteaza();
};

#endif