#ifndef MASINASTANDARD_H
#define MASINASTANDARD_H

#include "masina.h"

class masinaStandard : public masina{

public:
    masinaStandard(string nume = "Blank", motor* mot = new motorCombustibil());
    masinaStandard(const masinaStandard& m);
    masinaStandard& operator=(const masinaStandard& m);
    ~masinaStandard();

    void calculeaza_distanta(int greutate_circuit);
    void citire(istream&in);
    void generare_masina();
    void reseteaza();
};

#endif