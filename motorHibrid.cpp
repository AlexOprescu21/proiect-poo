#include "motorHibrid.h"

motorHibrid :: motorHibrid (int cai, int cuplu, string tip, int nivel, int baterie) : motor(cai, cuplu), motorCombustibil(cai, cuplu, tip, nivel),
    motorElectric(cai, cuplu, baterie) {}

motorHibrid :: motorHibrid(const motorHibrid& m) : motor(m), motorCombustibil(m), motorElectric(m) {
}

motorHibrid :: ~motorHibrid(){}

void motorHibrid :: afisare(ostream& out) const{
    motor :: afisare(out);
    out<<" Motorul este unul hibrid, avand o capacitate a bateriei de "<<this->baterie<<" si un nivel al rezervorului de "<<this->nivel_rezervor<<". ";
}

void motorHibrid :: generare_motor(){
    motorCombustibil :: generare_motor();
    motorElectric :: generare_motor();
    this->caiPutere = motorCombustibil::getCai() + motorElectric::getCai();
}

void motorHibrid :: consuma_resurse(){
    this->baterie = this->baterie - 15;
    this->nivel_rezervor = this->nivel_rezervor - 15;
}

motorHibrid* motorHibrid :: creeaza_motor() const{
    return new motorHibrid(*this);
}

void motorHibrid :: reseteaza(){
    motorCombustibil :: reseteaza();
    motorElectric :: reseteaza();
}

bool motorHibrid :: verifica_resurse(){
    if(nivel_rezervor <= 0 || baterie <= 0)
        return 0;
    return 1;
}

void motorHibrid :: citire(istream& in){
    motorCombustibil :: citire(in);
    cout<<"Nivelul bateriei este setat implicit la 100.\n";
}