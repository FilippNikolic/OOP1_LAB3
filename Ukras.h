//
// Created by nfili on 11/01/2023.
//

#ifndef ZADATAK3_UKRAS_H
#define ZADATAK3_UKRAS_H

#include "Boja.h"

class Ukras {

    int masa;
    Boja boja;


protected:
    virtual void pisi(ostream &os) const = 0;

public:
    Ukras(int m, Boja b): boja(b){
        boja = b;
        masa = m;
    }

    virtual ~Ukras(){}

    int dohvMasa() const{
        return masa;
    }

    Boja dohvBoja() const{
        return boja;
    }

    friend ostream &operator<<(ostream &os, const Ukras &u) {

        u.pisi(os);
        return os;
    }


};


#endif //ZADATAK3_UKRAS_H
