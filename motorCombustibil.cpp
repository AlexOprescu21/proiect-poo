#include "motorCombustibil.h"

motorCombustibil :: motorCombustibil(int caiPutere, int cuplu, string tipCombustibil, int nivel_rezervor) : motor(caiPutere, cuplu), tipCombustibil(tipCombustibil), nivel_rezervor(nivel_rezervor) {}

motorCombustibil :: motorCombustibil(const motorCombustibil& m) : motor(m){
    this->tipCombustibil = m.tipCombustibil;
    this->nivel_rezervor = m.nivel_rezervor;
}

motorCombustibil :: ~motorCombustibil() {}

void motorCombustibil :: afisare(ostream& out) const{
    motor :: afisare(out);
    out<<" Motorul este unul pe "<<this->tipCombustibil<<" si mai are "<<this->nivel_rezervor<<" L ramasi.";
}

void motorCombustibil :: generare_motor(){
    motor :: generare_motor();
    int val = rand() % 2;
    if(val == 0)
        this->tipCombustibil = "benzina";
    else
        this->tipCombustibil = "diesel";
}

void motorCombustibil :: consuma_resurse(){
    this->nivel_rezervor = this->nivel_rezervor - 15;
}

motorCombustibil* motorCombustibil :: creeaza_motor() const{
    return new motorCombustibil(*this);
}

void motorCombustibil :: reseteaza(){
    nivel_rezervor = 100;
}

bool motorCombustibil :: verifica_resurse(){
    if(nivel_rezervor <= 0)
        return 0;
    return 1;
}

void motorCombustibil :: citire(istream& in){
    motor::citire(in);
    cout<<"Tip combustibil(benzina/motorina): ";in>>tipCombustibil;
    cout<<"Nivelul rezervorului este setat implicit la 100.\n";
}