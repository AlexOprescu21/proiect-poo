#include "masinaF1.h"

masinaF1 :: masinaF1(string nume, motorHibrid* mot, int aerodinamica) : masina(nume, mot), aerodinamica(aerodinamica) {}

masinaF1 :: ~masinaF1(){}

masinaF1 :: masinaF1(const masinaF1 &m) : masina(m){
    this->aerodinamica = m.aerodinamica;
}

masinaF1& masinaF1 :: operator=(const masinaF1& m){
    masina :: operator=(m);
    this->aerodinamica = m.aerodinamica;
    return *this;
}

void masinaF1 :: afisare(ostream& out) const{
    masina :: afisare(out);
    out<<"\nIn plus, masina este una de Formula 1, avand o aerodinamica de "<<".";
}

void masinaF1 :: calculeaza_distanta(int greutate_circuit){
    if (!mot->verifica_resurse())
        return;
    int caiPutere = this->mot->getCaiPutere();
    int skill = this->p->getSkill();
    int cuplu = this->mot->getCuplu();

    int noroc = (rand()%50) + 50;

    int distanta = caiPutere * 0.5 + cuplu*0.2 + skill *2 - greutate_circuit + noroc + aerodinamica;
    this->mot->consuma_resurse();
    if (distanta < 0)
        distanta = 0;
    
    setDistanta(getDistanta() + distanta);
}

void masinaF1 :: afisare_jucator() const{
    masina::afisare_jucator();
    cout<<"\nIn plus, masina ta este una de Formula 1, avand o aerodinamica de "<<aerodinamica<<" .";
}

void masinaF1::generare_masina(){
    motor* motor_temp = new motorHibrid();
    motor_temp->generare_motor();
    int aero = rand() % 70 + 30;
    aerodinamica = aero;
    delete this->mot;
    this->mot = motor_temp;
}

void masinaF1::reseteaza(){
    this->distanta_parcursa = 0;
    this->mot->reseteaza();
}

void masinaF1 :: citire(istream& in){
    masina::citire(in);
    if (this->mot)
        delete this->mot;
    this->mot = new motorHibrid();
    in>>*(this->mot);
    cout<<"Aerodinamica: ";in>>aerodinamica;
}