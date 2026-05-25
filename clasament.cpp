#include "clasament.h"

template<>
void clasament<masina*> :: afisare() const{
    int cnt = 1;
    for(masina* m : elemente){
        cout<<cnt<<". "<<m->getPilot()->getNume()<<" -> "<<m->getDistanta()<<" m\n";
        cnt++;
    }
}