#ifndef PILOT_H
#define PILOT_H

#include <bits/stdc++.h>
using namespace std;

class pilot{
    string nume;
    int skill;
    int curse_castigate;

public:
    pilot(string nume = "blank", int skill = 0);

    string getNume() const;
    void setNume(string nume);

    int getSkill() const;
    void setSkill(int skill);
    int getCurse() const;

    void afisare(ostream&) const;
    void afisare_jucator() const;
    friend ostream& operator<<(ostream&, const pilot&);
    bool operator<(const pilot& p){
        return this->curse_castigate < p.curse_castigate;
    }
    void adauga_cursa_castigata();

    void genereaza_skill();
    void adauga_skill(int pct);
};

#endif