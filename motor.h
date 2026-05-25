#ifndef MOTOR_H
#define MOTOR_H

#include <bits/stdc++.h>
using namespace std;

class motor{
protected:
    int caiPutere;
    int cuplu;

public:
    motor(int caiPutere = 0, int cuplu = 0);
    virtual ~motor();

    int getCaiPutere() const;
    void setCaiPutere(int cp);

    int getCuplu() const;
    void setCuplu(int cuplu);

    virtual void afisare(ostream&) const;
    friend ostream& operator<<(ostream&, const motor&);
    friend istream& operator>>(istream& in, motor&);
    virtual void citire(istream& in);

    virtual void generare_motor();
    virtual void consuma_resurse();
    virtual bool verifica_resurse() = 0;
    virtual void reseteaza() = 0;

    virtual motor* creeaza_motor() const = 0;

    bool operator==(const motor& mot){
        return (this->caiPutere == mot.caiPutere && this->cuplu == mot.cuplu);
    }
};

#endif