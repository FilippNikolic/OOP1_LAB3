//
// Created by nfili on 11/01/2023.
//

#ifndef ZADATAK2_VREME_H
#define ZADATAK2_VREME_H

#include <iostream>
#include <iomanip>

class Vreme {

    int sati;
    int minuti;

public:

    Vreme(int s, int m) {
        sati = s;
        minuti = m;
    }

    ~Vreme(){};

    bool operator>(const Vreme &v) const {
        if (sati > v.sati)return true;
        else if (sati == v.sati && minuti > v.minuti)return true;
        return false;
    }

    Vreme operator+(const Vreme &v) {
        int t = minuti + v.minuti;
        minuti = (minuti + v.minuti) % 60;
        if (minuti != t) {
            t = t/60;
        } else {
            t = 0;
        }
        sati = sati + v.sati + t;
        return Vreme(v.sati,v.minuti);
    }

    friend std::ostream &operator<<(std::ostream &os, const Vreme &v) {
        os << std::setfill('0') << std::setw(2)<< v.sati  << ":" << std::setfill('0') << std::setw(2)<< v.minuti
           << std::endl;
        return os;
    }

};


#endif //ZADATAK2_VREME_H
