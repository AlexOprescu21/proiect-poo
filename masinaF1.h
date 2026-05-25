#ifndef MASINAF1_H
#define MASINAF1_H

#include "masina.h"

class masinaF1 : public masina{
    int aerodinamica;
public:
    masinaF1(string nume = "Blank", motorHibrid* mot = NULL, int aerodinamica = 0);
    masinaF1(const masinaF1& m);
    masinaF1& operator=(const masinaF1 &m);
    ~masinaF1();

    void calculeaza_distanta(int greutate_circuit);
    void afisare(ostream& out) const;
    void citire(istream& in);
    void afisare_jucator() const;
    void generare_masina();
    void reseteaza();

    
};

#endif