#include "motor.h"

motor :: ~motor(){}

motor::motor(int caiPutere, int cuplu){
    this->caiPutere = caiPutere;
    this->cuplu = cuplu;
}

int motor::getCaiPutere() const{
    return this->caiPutere;
}

void motor::setCaiPutere(int cp){
    this->caiPutere = cp;
}

int motor::getCuplu() const{
    return this-> cuplu;
}

void motor::setCuplu(int cuplu){
    this->cuplu = cuplu; 
}

void motor::afisare(ostream& out) const{
    out<<this->caiPutere<<" CP si "<<this->cuplu<<" NM.";
}

ostream& operator<<(ostream& out, const motor& m){
    m.afisare(out);
    return out;
}

void motor::generare_motor(){
    int cai = (rand() % 200) + 100;
    int cuplu = (rand() % 350) + 100;
    setCaiPutere(cai);
    setCuplu(cuplu);
}

void motor :: consuma_resurse(){}

istream& operator>>(istream&in, motor& m){
    m.citire(in);
    return in;
}

void motor :: citire(istream& in){
    cout<<"Introdu atributele motorului: \n";
    cout<<"Cai putere: "; in>>caiPutere;
    cout<<"Cuplu: ";in>>cuplu;
}