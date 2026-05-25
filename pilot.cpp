#include "pilot.h"

pilot::pilot(string nume, int skill){
    curse_castigate = 0;
    this->nume = nume;
    this->skill = skill;
}

string pilot::getNume() const{
    return this->nume;
}

void pilot::setNume(string nume){
    this->nume = nume;
}

int pilot::getSkill() const{
    return this->skill;
}

void pilot::setSkill(int skill){
    this->skill = skill;
}

void pilot::afisare(ostream& out) const{
    out<<nume<<" are "<<curse_castigate<<" curse castigate! "<<"Acesta are skill-ul "<<skill<<"\n";
}

ostream& operator<<(ostream& out, const pilot& p){
    p.afisare(out);
    return out;
}

void pilot::genereaza_skill(){
    int numar = (rand() % 50) + 1;
    setSkill(numar);
}

void pilot::adauga_skill(int pct){
    setSkill(getSkill() + pct);
}

int pilot::getCurse() const {return curse_castigate;}

void pilot::afisare_jucator() const{
    cout<<"Numele tau este "<<nume<<" si ai "<<curse_castigate<<" curse castigate. In plus ai skill -ul "<<skill<<".\n";
}

void pilot :: adauga_cursa_castigata(){
    curse_castigate++;
}