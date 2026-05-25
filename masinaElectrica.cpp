#include "masinaElectrica.h"

masinaElectrica::masinaElectrica(string nume, motorElectric* mot, int acceleratie) : masina(nume, mot), acceleratie(acceleratie){}

masinaElectrica :: masinaElectrica(const masinaElectrica& m) : masina(m){
    this->acceleratie = m.acceleratie;

}

masinaElectrica& masinaElectrica :: operator=(const masinaElectrica& m){
    masina::operator=(m);
    this->acceleratie = m.acceleratie;
    return *this;
}

masinaElectrica::~masinaElectrica(){}

void masinaElectrica::calculeaza_distanta(int greutate_circuit){
    int caiPutere = this->mot->getCaiPutere();
    int skill = this->p->getSkill();
    int cuplu = this->mot->getCuplu();
    int acceleratie = this->acceleratie;

    if (!mot->verifica_resurse())
        return;

    int noroc = (rand()%50) + 50;

    int distanta = caiPutere * 0.5 + cuplu*0.2 + skill *2 - greutate_circuit + noroc + acceleratie;
    this->mot->consuma_resurse();
    if (distanta < 0)
        distanta = 0;
    
    setDistanta(getDistanta() + distanta);
}

void masinaElectrica::afisare(ostream& out) const{
    masina::afisare(out);
    out<<"\nIn plus, masina este una electrica, avand o acceleratie instanta de "<<this->acceleratie<<".";
}

void masinaElectrica::afisare_jucator() const{
    masina::afisare_jucator();
    cout<<"\nIn plus, masina ta este una electrica, avand o acceleratie instanta de "<<this->acceleratie<<".";
}

void masinaElectrica::generare_masina(){
    motor* motor_temp = new motorElectric();
    motor_temp->generare_motor();
    delete this->mot;
    this->mot = motor_temp;
    int acceleratie = (rand() % 70) + 30;
    setAcceleratie(acceleratie);
}

void masinaElectrica::reseteaza(){
    this->distanta_parcursa = 0;
    mot->reseteaza();
}

void masinaElectrica :: citire(istream& in){
    masina::citire(in);
    cout<<"Acceleratie: ";in>>acceleratie;
}