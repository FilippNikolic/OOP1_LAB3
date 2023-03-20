//
// Created by nfili on 11/01/2023.
//

#ifndef ZADATAK3_KUGLA_H
#define ZADATAK3_KUGLA_H

#include "Ukras.h"


class Kugla : public Ukras {

    int vel;

public:
    enum velicina {
        MALA = 1, SREDNJA, VELIKA, NAJVECA = 4
    };

    Kugla(velicina p, int m, Boja b) : Ukras(m,b) {
        vel = p;
    }

    ~Kugla(){}

    void pisi(ostream &os) const override{
        dohvBoja().pisi(os);
        os << " " << "masa:" << dohvMasa();
        os << " ";
        switch (vel) {
            case 1: {
                os << ".";
                break;
            }
            case 2: {
                os << "o";
                break;
            }
            case 3: {
                os << "O";
                break;
            }
            case 4: {
                os << "()";
                break;
            }
        }
    }

    friend ostream &operator<<(ostream &os, const Kugla &k) {
        k.pisi(os);
        return os;
    }


};


#endif //ZADATAK3_KUGLA_H
