#ifndef GAME_H
#define GAME_H

#include "masina.h"
#include "masinaF1.h"
#include "masinaStandard.h"
#include "masinaElectrica.h"
#include "masinaOffRoad.h"
#include "exceptii.h"
#include "garaj.h"
#include "clasament.h"

enum Dificultate {EASY, MEDIUM, HARD};

class game{
    masina* masina_jucator;
    pilot jucator;
    vector <masina*> adversari;
    list <pilot> piloti;
    int bani;
    Dificultate dificultate;
    game(){
        bani = 10000;
        masina_jucator =  new masinaStandard("Opel Astra G", new motorCombustibil(90, 250, "diesel"));
    }
    static game *instance;

public:
    static game *getInstance(){
        if(!instance)
            instance = new game();
        return instance;
    }
    game(const game& g) = delete;
    game& operator=(const game& g) = delete;
    ~game();
    void uiMeniu();
    void citire_adversari();
    void afisare_adversari();
    void adversari_impliciti();
    void statistici_personale();
    void meniu();
    void start_cursa();
    void victorii() const;
};

#endif