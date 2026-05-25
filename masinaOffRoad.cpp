#include "masinaOffRoad.h"

masinaOffRoad :: masinaOffRoad(string nume, motorCombustibil* mot, int tractiune, bool diferential) : masina(nume, mot), diferential(diferential), tractiune(tractiune){}

masinaOffRoad :: masinaOffRoad(const masinaOffRoad& m) : masina(m){
    this->tractiune = m.tractiune;
    this->diferential = m.diferential;
}

masinaOffRoad& masinaOffRoad :: operator=(const masinaOffRoad& m){
    masina :: operator=(m);
    this->tractiune = m.tractiune;
    this->diferential = m.diferential;
    return *this;
}

masinaOffRoad :: ~masinaOffRoad(){}

void masinaOffRoad :: calculeaza_distanta(int greutate_circuit){
    if (!mot->verifica_resurse())
        return;

    int caiPutere = this->mot->getCaiPutere();
    int skill = this->p->getSkill();
    int cuplu = this->mot->getCuplu();
    int tractiune = this->tractiune;
    bool diferential = this->diferential;

    int noroc = (rand()%50) + 50;
    int bonus = 0;

    if(diferential && greutate_circuit > 60)
        bonus = 50;
    else
        bonus = 10;

    int distanta = caiPutere * 0.5 + cuplu*0.2 + skill *2 - greutate_circuit + noroc + tractiune + bonus;
    if (distanta < 0)
        distanta = 0;
    this->mot->consuma_resurse();
    
    setDistanta(getDistanta() + distanta);
}

void masinaOffRoad:: afisare(ostream& out) const{
    masina::afisare(out);
    if(this->diferential)
        out<<"\nIn plus, masina este una de Off Road, avand o tractiune de "<<this->tractiune<<" cu diferential auto-blocant.";
    else
        out<<"\nIn plus, masina este una de Off Road, avand o tractiune de "<<this->tractiune<<" fara diferential auto-blocant.";
}

void masinaOffRoad::afisare_jucator() const{
    masina::afisare_jucator();
    if(this->diferential)
        cout<<"\nIn plus, masina ta este una de Off Road, avand o tractiune de "<<this->tractiune<<" cu diferential auto-blocant.";
    else
        cout<<"\nIn plus, masina ta este una de Off Road, avand o tractiune de "<<this->tractiune<<" fara diferential auto-blocant.";
}

void masinaOffRoad::generare_masina(){
    motor* motor_temp = new motorCombustibil();
    motor_temp->generare_motor();
    delete this->mot;
    this->mot = motor_temp;
    int tractiune = (rand() % 70) + 30;
    bool diferential = (rand() % 2);
    setTractiune(tractiune);
    setDiferential(diferential);
}

void masinaOffRoad :: reseteaza(){
    this->distanta_parcursa = 0;
    this->mot->reseteaza();
}

void masinaOffRoad :: citire(istream& in){
    masina::citire(in);
    if (this->mot)
        delete this->mot;
    this->mot = new motorCombustibil();
    in>>*(this->mot);
    cout<<"Tractiune: ";in>>tractiune;
    cout<<"Diferential (1-da, 0-nu): ";in>>diferential;

}
