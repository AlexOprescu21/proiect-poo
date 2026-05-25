#include "masinaStandard.h"

masinaStandard :: masinaStandard(string nume, motor* mot) : masina(nume, mot){}

masinaStandard :: masinaStandard(const masinaStandard& m) : masina(m){}

masinaStandard& masinaStandard :: operator=(const masinaStandard& m){
    masina :: operator=(m);
    return *this;
}

masinaStandard :: ~masinaStandard(){}

void masinaStandard :: calculeaza_distanta(int greutate_circuit){
    if (!mot->verifica_resurse())
        return;
    
    int caiPutere = this->mot->getCaiPutere();
    int skill = this->p->getSkill();
    int cuplu = this->mot->getCuplu();

    int noroc = (rand()%50) + 50;

    int distanta = caiPutere * 0.5 + cuplu*0.2 + skill *2 - greutate_circuit + noroc;
    if (distanta < 0)
        distanta = 0;
    
    setDistanta(getDistanta() + distanta);
}


void masinaStandard::generare_masina(){
    motor* motor_temp = new motorCombustibil();
    motor_temp->generare_motor();
    delete this->mot;
    this->mot = motor_temp;
}

void masinaStandard :: reseteaza(){
    this->mot->reseteaza();
    this->distanta_parcursa = 0;
}

void masinaStandard :: citire(istream& in){
    masina::citire(in);
    if (this->mot)
        delete this->mot;
    this->mot = new motorCombustibil();
    in>>*(this->mot);
}
