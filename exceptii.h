#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
using namespace std;

class ExceptieBaniInsuficienti : public exception{
public:
    const char* what() const noexcept{
        return "Nu ai bani suficienti!";
    }
};

class ExceptieMotor : public exception{
public:
    const char* what() const noexcept{
        return "Ai deja un motor mai bun!";
    }
};

class ExceptieMasinaOffRoad : public exception{
public:
    const char* what() const noexcept{
        return "Nu poti alege aceasta optiune, deoarece masina ta nu este una de Off Road!";
    }
};

#endif