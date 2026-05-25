#include "motorElectric.h"

motorElectric :: motorElectric(int cai, int cuplu, int baterie) : motor(cai, cuplu), baterie(baterie) {}

motorElectric :: motorElectric(const motorElectric& m) : motor(m){
    this->baterie = m.baterie;
}

motorElectric :: ~motorElectric() {}

void motorElectric :: afisare(ostream& out) const{
    motor :: afisare(out);
    out<<" Motorul este unul electric si are o capacitate ramasa a bateriei de "<<this->baterie<<".";
}

void motorElectric :: generare_motor(){
    motor :: generare_motor();
    int baterie = (rand()%51) + 50;
    this->baterie = baterie;
}

void motorElectric :: consuma_resurse(){
    this->baterie = this->baterie - 15;
}

motorElectric* motorElectric :: creeaza_motor() const{
    return new motorElectric(*this);
}

void motorElectric :: reseteaza(){
    baterie = 100;
}

bool motorElectric :: verifica_resurse(){
    if(baterie <= 0)
        return 0;
    return 1;
}

void motorElectric :: citire(istream& in){
    motor::citire(in);
    cout<<"Nivelul bateriei este setat implicit la 100.\n";
}