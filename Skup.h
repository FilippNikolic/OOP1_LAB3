//
// Created by nfili on 12/01/2023.
//

#ifndef ZADATAK1_SKUP_H
#define ZADATAK1_SKUP_H

#include <iostream>
#include <string>

using namespace std;

class Skup {
    string niska;
public:

    Skup(string n) {
        niska = n;
    }

    Skup(const Skup &) = delete;

    Skup &operator+=(char r) {
        if (operator()(r))return *this;
        niska = niska + r;
        return *this;
    }

    bool operator()(char r) {
        for (int i = 0; i < size(niska); i++) {
            if (niska[i] == r) return true;
        }
        return false;
    }


};


#endif //ZADATAK1_SKUP_H
