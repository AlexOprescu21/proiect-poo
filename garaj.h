#ifndef GARAJ_H
#define GARAJ_H

#include "masina.h"
#include "masinaElectrica.h"
#include "masinaOffRoad.h"
#include "masinaF1.h"
#include "pilot.h"

class garaj{
public:
    void upgrade_masina(masina* &masina_jucator, int& bani);
    void cumpara_masina(masina* &masina_jucator, pilot& jucator, int& bani);
    void meniu_garaj(masina* &masina_jucator, pilot& jucator, int& bani);
    void update_masina(masina* &masina_jucator, pilot& jucator, masina* m);
};

#endif