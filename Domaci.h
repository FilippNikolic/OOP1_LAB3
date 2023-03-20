//
// Created by nfili on 11/01/2023.
//

#ifndef ZADATAK2_DOMACI_H
#define ZADATAK2_DOMACI_H

#include "Film.h"

class Domaci : public Film {

public:
    Domaci(string n, Vreme v) : Film(n, v) {
    }

    char dohvOznaku() override {
        return 'D';
    }

    friend ostream &operator<<(ostream &os, Domaci &f) {
        os << f.dohvOznaku() << " ";
        f.pisi(os);
        return os;
    }

};


#endif //ZADATAK2_DOMACI_H
