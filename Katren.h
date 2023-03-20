//
// Created by nfili on 13/01/2023.
//

#ifndef ZADATAK1_KATREN_H
#define ZADATAK1_KATREN_H

#include "Strofa.h"


class Katren : public Strofa {
public:
    Katren() : Strofa(4) {}

    ~Katren() override {}

    Katren &operator+=(Stih &s) override {
        int b = 0;
        for (Elem *tmp = prvi; tmp; tmp = tmp->sled) {
            b++;
        }
        if (b == dohvBrStihova())return *this;

        if (!prvi) {
            posl = prvi = new Elem(s);
        } else {
            if (~prvi->info != ~s)return *this;
            posl = posl->sled = new Elem(s);
        }

        if (prvi == posl || posl == prvi->sled)return *this;

        if (posl == prvi->sled->sled) {
            if (!(prvi->sled->info ^ prvi->sled->sled->info))-*this;
        } else {
            if (!(prvi->info ^ prvi->sled->sled->sled->info))-*this;
        }
        return *this;
    }

    char dohvVrstuStrofe() const override {
        return 'K';
    }

};


#endif //ZADATAK1_KATREN_H
