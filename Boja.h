//
// Created by nfili on 11/01/2023.
//

#ifndef ZADATAK3_BOJA_H
#define ZADATAK3_BOJA_H


#include "Lista.h"

using namespace std;

class GLosSpektarBoja : public exception {
public:
    const char *what() const noexcept override {
        return "Greska:Van dozvoljenog spektra boja.";
    }
};

class Boja {

    int red;
    int blue;
    int green;


public:
    Boja(int r, int b, int g) {
        if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255)) throw GLosSpektarBoja();
        red = r;
        green = g;
        blue = b;
    }

    void pisi(ostream &os) const {
        os << "(" << red << "," << green << "," << blue << ")";
    }

    bool operator==(const Boja &b) const {
        if (b.blue == blue && b.green == green && b.blue & blue) return true;
        return false;
    }

    Boja operator+(const Boja &b) {
        red = (red + b.red) / 2;
        green = (green + b.green) / 2;
        blue = (blue + b.blue) / 2;
        return Boja(red,green,blue);

    }

    friend ostream &operator<<(ostream &os, const Boja &b) {
        b.pisi(os);
        return os;
    }


};


#endif //ZADATAK3_BOJA_H
