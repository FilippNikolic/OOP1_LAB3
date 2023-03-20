//
// Created by nfili on 11/01/2023.
//

#ifndef ZADATAK2_LISTA_H
#define ZADATAK2_LISTA_H

#include <exception>
#include <iostream>

using namespace std;

class GVanObsega : public exception {
public:
    const char *what() const noexcept override {
        return "Greska:Index je van obsega.";
    }
};


template<typename T>
class Lista {
    struct Elem {
        T pod;
        Elem *sled;

        Elem(const T &t, Elem *s = nullptr) {
            pod = t;
            sled = s;
        }

    };

    int brPod;
    Elem *prvi, *posl;

    void kopiraj(const Lista &l) {
        prvi = posl = nullptr;
        int t = l.dohvBrPod();
        brPod = t;
        for (Elem *pok = l.prvi; pok; pok = pok->sled) {
            Elem *novi = new Elem(pok->pod);
            posl = (!prvi ? prvi : posl->sled) = novi;
            t--;
            if (!t)break;

        }
    }

    void isprazni();

    void premesti(Lista &l) {
        prvi = l.prvi;
        l.prvi = nullptr;

        posl = l.posl;
        l.posl = nullptr;

        brPod = l.brPod;
        l.brPod = 0;

    }

public:

    Lista() {
        brPod = 0;
        prvi = posl = nullptr;
    }

    Lista(const Lista &l) {
        kopiraj(l);
    }

    Lista(Lista &&l) {
        premesti(l);
    }

    ~Lista() {
        isprazni();
    }

    Lista &operator=(const T &t) {
        if (this != &t) {
            isprazni();
            kopiraj(t);
        }
    }

    Lista &operator=(T &&t) {
        if (this != &t) {
            isprazni();
            premesti(t);
        }
    }


    Lista &operator+=(const T &t) {
        posl = (!prvi ? prvi : posl->sled) = new Elem(t);
        brPod++;
        return *this;
    }

    int dohvBrPod() const {
        return brPod;
    }

    T &operator[](int i) {
        if (i >= brPod) throw GVanObsega();
        Elem *tmp = prvi;
        for (int j = 0; j < i; j++) {
            tmp = tmp->sled;
        }
        return tmp->pod;
    }

    const T &operator[](int i) const {
        if (i >= brPod && i < 0) throw GVanObsega();
        Elem *tmp = prvi;
        for (int j = 0; j < i; j++) {
            tmp = tmp->sled;
        }
        return tmp->pod;
    }

    friend ostream &operator<<(ostream &os, const Lista &l) {
        for (int i = 0; i < l.brPod; i++) {
            os << *l[i] << endl;
        }
        return os;
    }

};


template<typename T>
void Lista<T>::isprazni() {
    if (posl)posl->sled = nullptr;
    while (prvi) {
        Elem *stari = prvi;
        prvi = prvi->sled;
        delete stari;
    }
    posl = nullptr;
    brPod = 0;
}


#endif //ZADATAK2_LISTA_H
