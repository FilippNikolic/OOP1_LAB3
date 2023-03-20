//
// Created by nfili on 12/01/2023.
//

#ifndef ZADATAK1_REC_H
#define ZADATAK1_REC_H

#include <iostream>
#include <string>

using namespace std;

class Rec {
    string rec;
public:

    Rec() {};

    Rec(string r) {
        rec = r;
    }

    int operator+() {
        return size(rec);
    }

    int operator~() {
        int brSlogova = 0;
        for (int i = 0; i < size(rec); i++) {
            switch (rec[i]) {
                case 'u':
                case 'o':
                case 'i':
                case 'a':
                case 'e' : {
                    brSlogova++;
                    break;
                }
                case 'n':
                case 'l': {
                    if (rec[i - 1] == 'j')break;
                }
                case 'r': {
                    if (rec[i - 1] != 'a' && rec[i - 1] != 'e' && rec[i - 1] != 'i' && rec[i - 1] != 'o' &&
                        rec[i - 1] != 'u' && rec[i + 1] != 'a' && rec[i + 1] != 'e' && rec[i + 1] != 'i' &&
                        rec[i + 1] != 'o' &&
                        rec[i + 1] != 'u') {
                        brSlogova++;
                    }
                }
                default: {
                    continue;
                }
            }
        }
        return brSlogova;
    }

    int operator()(int n) {
        if (n < 0) {
            n = ~*this + n;
        }
        int brSlogova = 0;
        for (int i = 0; i < size(rec); i++) {
            switch (rec[i]) {
                case 'u':
                case 'o':
                case 'i':
                case 'a':
                case 'e' : {
                    brSlogova++;
                    break;
                }
                case 'n':
                case 'l': {
                    if (rec[i - 1] == 'j')break;
                }
                case 'r': {
                    if (rec[i - 1] != 'a' && rec[i - 1] != 'e' && rec[i - 1] != 'i' && rec[i - 1] != 'o' &&
                        rec[i - 1] != 'u' && rec[i + 1] != 'a' && rec[i + 1] != 'e' && rec[i + 1] != 'i' &&
                        rec[i + 1] != 'o' &&
                        rec[i + 1] != 'u') {
                        brSlogova++;
                    }
                }
            }
            if (brSlogova - 1 == n) {
                return i;
            }
        }
        return -1;
    }

    bool operator^(Rec &s) {
        int f = 0;
        int i, j;
        if (~*this <= 1 || ~s <= 1)f = 1;
        if (!f) {
            i = this->operator()(-2);
            j = s.operator()(-2);
        } else {
            i = this->operator()(-1);
            j = s.operator()(-1);
        }
        if ((size(rec) - i) != (size(s.rec) - j))return false;
        for (int n = 0; n < size(rec) - i; n++) {
            if (rec[n + i] != s.rec[n + j])return false;
        }
        return true;
    }

    friend istream &operator>>(istream &is, Rec &r) {
        is >> r.rec;
        for (int i = 0; i < size(r.rec); i++) {
            if (!((r.rec[i] >= 65 && r.rec[i] <= 90) || (r.rec[i] >= 97 && r.rec[i] <= 122))) {
                for (int j = i; j < size(r.rec); j++) {
                    r.rec[i] = r.rec[i + 1];
                }
            }
        }

        return is;
    }

    friend ostream &operator<<(ostream &os, Rec &r) {
        return os << r.rec;
    }

};


#endif //ZADATAK1_REC_H
