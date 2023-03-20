//
// Created by nfili on 11/01/2023.
//

#ifndef ZADATAK2_STRANI_H
#define ZADATAK2_STRANI_H


#include "Film.h"

class Strani : public Film {

    string zemlja;
    int tit;

public:
    enum titl {
        TTILOVAN = 1, SINHRONIZOVAN = 2
    };

    Strani(string z, string n, Vreme v, titl t) : Film(n, v) {
        zemlja = z;
        tit = t;
    }

    char dohvOznaku() override {
        return 'S';
    }

    friend ostream &operator<<(ostream &os, Strani &f) {
        os << f.zemlja << " " << f.dohvOznaku() << " ";
        f.pisi(os);
        if(f.tit == 1) os << " TITLOVAN";
        else os << " SINHRONIZOVAN";
        return os;
    }

};


#endif //ZADATAK2_STRANI_H
