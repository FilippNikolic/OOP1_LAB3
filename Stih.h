//
// Created by nfili on 12/01/2023.
//

#ifndef ZADATAK1_STIH_H
#define ZADATAK1_STIH_H

#include "Rec.h"
#include <exception>

class GIndex : public exception {
public:
    const char *what() const noexcept override {
        return "Greska:Van indeksnih vrednosti";
    }
};

class Stih {
    struct Elem {
        Rec info;
        Elem *sled;

        Elem(const Rec &r, Elem *s = nullptr) {
            info = r;
            sled = s;
        }
    };

    Elem *prvi = NULL, *posl;


public:
    Stih() {}

    Stih &operator+=(const Rec &r) {
        if (!prvi) {
            posl = prvi = new Elem(r);
        } else {
            posl = posl->sled = new Elem(r);
        }
        return *this;
    }

    int operator+() {
        int broj = 0;
        for (Elem *tmp = prvi; tmp; tmp = tmp->sled) {
            broj++;
        }
        return broj;
    }

    int operator~() {
        int broj = 0;
        for (Elem *tmp = prvi; tmp; tmp = tmp->sled) {
            broj += ~tmp->info;
        }
        return broj;
    }

    Rec &operator[](int indx) {
        if (+*this <= indx && indx < 0)throw GIndex();
        int broj = 0;
        for (Elem *tmp = prvi; tmp; tmp = tmp->sled) {
            if (++broj == indx + 1)return tmp->info;
        }
    }

    void operator()(int indx) {
        Elem *tmp;
        if (+*this <= indx && indx < 0)throw GIndex();
        if (!indx) {
            tmp = prvi->sled;
            delete prvi;
            prvi = tmp;
            return;
        }

        int broj = 0;
        for (tmp = prvi; tmp; tmp = tmp->sled) {
            if (indx == ++broj) {
                Elem *tmp2 = tmp->sled;
                tmp->sled = tmp2->sled;
                tmp2->sled = nullptr;
                delete tmp2;
                if (indx == ~*this - 1)posl = tmp;
                return;
            }
        }
    }

    void operator()(Rec &r, int indx) {

        Elem *tmp;
        if (+*this + 1 <= indx && indx < 0)throw GIndex();
        int broj = 0;
        for (tmp = prvi; tmp; tmp = tmp->sled) {
            if (indx + 1 == ++broj) {
                Elem *tmp2 = new Elem(r);
                tmp2->sled = tmp->sled;
                tmp->sled = tmp2;
                if (tmp2->sled == nullptr)posl = tmp2;
                return;
            }
        }
    }

    bool operator^(Stih &s) {
        if (this->operator[](+*this - 1) ^ s[+s - 1])return true;
        return false;
    }

    friend istream &operator>>(istream &is, Stih &s) {
        int i = 1, br = 0;

        string str;
        getline(is, str);
        if (str == "") {
            getline(is, str);
        }
        string reci = "";
        for (auto x: str) {
            if (x == ' ') {
                Rec r(reci);
                s += r;
                br++;
                reci = "";
            } else {
                reci = reci + x;
            }
        }
        Rec r(reci);
        s += r;
        br++;
        reci = "";

        return is;
    }

    friend ostream &operator<<(ostream &os, Stih &s) {
        Elem *tmp = s.prvi;
        int t = +s;
        for (int i = 0; i < +s; i++, tmp = tmp->sled) {
            os << tmp->info << " ";
        }
        return os;
    }

};


#endif //ZADATAK1_STIH_H
