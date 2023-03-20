//
// Created by nfili on 12/01/2023.
//

#ifndef ZADATAK1_STROFA_H
#define ZADATAK1_STROFA_H

#include "Stih.h"


class Strofa {

    int brStihova;

protected:
    struct Elem {
        Stih info;
        Elem *sled;

        Elem(const Stih &r, Elem *s = nullptr) {
            info = r;
            sled = s;
        }
    };

    Elem *prvi = NULL, *posl;

public:

    Strofa(int b) {
        brStihova = b;
    }

    virtual ~Strofa() {}

    int dohvBrStihova() const {
        return brStihova;
    }

    virtual Strofa &operator+=(Stih &s) {
        int b = 0;
        for (Elem *tmp = prvi; tmp; tmp = tmp->sled) {
            b++;
        }
        if (b == brStihova)return *this;

        if (!prvi) {
            posl = prvi = new Elem(s);
        } else {
            if (~prvi->info != ~s)return *this;
            posl = posl->sled = new Elem(s);
        }

        return *this;
    }

    Strofa &operator-() {
        Elem *tmp;
        if (prvi == NULL)return *this;
        for (tmp = prvi; tmp->sled->sled; tmp = tmp->sled) {

        }
        Elem *tmp2 = tmp->sled;
        tmp->sled = nullptr;
        posl = tmp;
        delete tmp2;
        return *this;
    }

    int operator+() const{
        int b = 0;
        for (Elem *tmp = prvi; tmp; tmp = tmp->sled) {
            b++;
        }
        return b;
    }

    Stih &operator[](int indx) const{
        if (+*this <= indx && indx < 0)throw GIndex();
        int b = 0;
        for (Elem *tmp = prvi; tmp; tmp = tmp->sled) {
            b++;
            if (indx == b - 1)return tmp->info;
        }
    };

    Elem *operator/(int indx) {
        if (+*this <= indx && indx < 0)throw GIndex();
        int b = 0;
        for (Elem *tmp = prvi; tmp; tmp = tmp->sled) {
            b++;
            if (indx == b - 1)return tmp;
        }
    };

    void operator()(int i, int j) {
        Elem *tek1 = *this / i, *tek2 = *this / j, *pre1, *pre2;
        if (i == 0 || j == 0) {
            if (i == 0) {
                pre2 = *this / (--j);
                Elem *p = tek1->sled;
                tek1->sled = tek2->sled;
                tek2->sled = p;
                pre2->sled = tek1;
                prvi = tek2;
                return;
            } else {
                pre1 = *this / (--j);
                Elem *p = tek1->sled;
                tek1->sled = tek2->sled;
                tek2->sled = p;
                pre1->sled = tek2;
                prvi = tek1;
                return;
            }
        } else {
            pre1 = *this / (--i);
            pre2 = *this / (--j);
            Elem *p = tek1->sled;
            tek1->sled = tek2->sled;
            tek2->sled = p;
            pre1->sled = tek2;
            pre2->sled = tek1;
            return;
        }
    }

    bool operator*() {
        Elem *tek = prvi->sled;
        for (Elem *tmp = prvi; tek; tmp = tmp->sled, tek = tek->sled) {
            if (!(tek->info ^ tmp->info))return false;
        }
        return true;
    }

    virtual char dohvVrstuStrofe() const = 0;

    friend istream &operator>>(istream &is, Strofa &s) {

        for (int i = 0; i < s.dohvBrStihova(); i++) {
            Stih s1;
            is >> s1;
            s += s1;
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, Strofa &s) {
        for (Elem *tmp = s.prvi; tmp; tmp = tmp->sled) {
            os << tmp->info << endl;
        }
        return os;
    }
};


#endif //ZADATAK1_STROFA_H
