#ifndef MASINA_H
#define MASINA_H

#include "motor.h"
#include "pilot.h"
#include "motorElectric.h"
#include "motorCombustibil.h"
#include "motorHibrid.h"

class masina{
protected:
    static int contor;
    string marca;
    motor* mot;
    pilot* p;
    int distanta_parcursa;

public:
    masina(string marca = "blank", motor* mot = NULL);
    masina(const masina& m);
    masina& operator=(const masina& m);
    virtual ~masina();

    void setPilot(pilot* pilot_nou);
    void setDistanta(int distanta);
    void setMotor(motor* mot);
    int static getContor();

    int getDistanta();
    string getMarca();
    pilot* getPilot();
    motor* getMotor();

    void upgrade(int cp);
    virtual void calculeaza_distanta(int greutate_circuit) = 0;
    virtual void generare_masina() = 0;
    virtual void reseteaza();

    friend ostream& operator<<(ostream&, const masina&);
    friend istream& operator>>(istream&, masina&);

    virtual void afisare(ostream&) const;
    virtual void afisare_jucator() const;
    virtual void citire(istream&);

    bool operator<(const masina& m){
        return this->distanta_parcursa < m.distanta_parcursa;
    }

    bool operator==(const masina& m){
        return (this->marca == m.marca && *this->mot == *m.mot && this->p == m.p && this->distanta_parcursa == m.distanta_parcursa); 
    }
};

#endif