#ifndef CLASAMENT_H
#define CLASAMENT_H

#include "masina.h"

template<typename T>
class clasament{
    vector<T> elemente;
public:
    void adauga(T element){
        elemente.push_back(element);
    }
    template<typename comparator>
    void sortare(comparator comp){
        sort(elemente.begin(), elemente.end(), comp);
    }
    void afisare() const{
        int cnt = 1;
        for(T element : elemente){
            cout<<cnt<<". "<<element<<"\n";
            cnt++;
        }
    }
    vector<T> getElemente() const{ return elemente;}
};

template<>
void clasament<masina*>::afisare() const;
#endif