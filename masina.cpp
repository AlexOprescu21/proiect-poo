#include "masina.h"

int masina :: contor = 0;

masina::masina(string marca, motor* mot){
    contor++;
    this->marca = marca;
    this->mot = mot;
    this->p = NULL;
    this->distanta_parcursa = 0;
}

masina::masina(const masina& m){
    this->marca = m.marca;
    this->distanta_parcursa = m.distanta_parcursa;
    this->p = m.p;
    if (m.mot != NULL){
        motor* nou = m.mot->creeaza_motor();
        this->mot = nou;
    }
    else{
        this->mot = NULL;
    }
}

masina& masina :: operator=(const masina& m){
    this->marca = m.marca;
    this->distanta_parcursa = m.distanta_parcursa;
    this->p = m.p;
    delete this->mot;
    if (m.mot != NULL){
        motor* nou = m.mot->creeaza_motor();
        this->mot = nou;
    }
    else{
        this->mot = NULL;
    }
    return *this;
}

masina::~masina(){
    delete this->mot;
    contor--;
}

int masina::getDistanta(){
    return this->distanta_parcursa;
}

string masina::getMarca(){
    return this->marca;
}

pilot* masina::getPilot(){
    return p;
}

motor* masina::getMotor(){
    return this->mot;
}

void masina::setDistanta(int distanta){
    this->distanta_parcursa = distanta;
}

void masina::setPilot(pilot* pilot_nou){
    this->p = pilot_nou;
}

void masina::reseteaza(){
    this->distanta_parcursa = 0;
}

void masina::afisare(ostream& out) const{
    out<<*(this->p)<<"Acesta conduce un "<<this->marca<<" cu "<<*this->mot;
}

ostream& operator<<(ostream& out, const masina& m){
    m.afisare(out);
    return out;
}

void masina::citire(istream& in){
    cout<<"Introdu datele masinii: \n";
    cout<<"Marca: ";in>>marca;
}

istream& operator>>(istream& in, masina& m){
    m.citire(in);
    return in;
}

void masina::setMotor(motor* mot){
    this->mot = mot;
}

void masina::upgrade(int cp){
    this->mot->setCaiPutere(cp);
}

int masina::getContor(){return contor;}

void masina::afisare_jucator() const{
    cout<<"Tu conduci un "<<marca<<" cu "<<*mot;
}