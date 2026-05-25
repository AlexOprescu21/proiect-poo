#ifndef MASINAELECTRICA_H
#define MASINAELECTRICA_H

#include "masina.h"

class masinaElectrica : public masina{
    int acceleratie;

public:
    masinaElectrica(string nume = "Blank", motorElectric* mot = NULL, int acceleratie = 0);
    masinaElectrica(const masinaElectrica& m);
    masinaElectrica& operator=(const masinaElectrica& m);
    ~masinaElectrica();

    void calculeaza_distanta(int greutate_circuit);
    void afisare(ostream& out) const;
    void citire(istream& in);
    void afisare_jucator() const;
    void generare_masina();
    void reseteaza();

    void setAcceleratie(int acceleratie){
        this->acceleratie = acceleratie;
    }
};

#endif