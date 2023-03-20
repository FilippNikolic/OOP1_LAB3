//
// Created by nfili on 09/01/2023.
//

#ifndef V_SABLONI_LISTA_H
#define V_SABLONI_LISTA_H

#include <iostream>

class GNemaTek {
    friend std::ostream &operator<<(std::ostream &os, const GNemaTek &g) {
        return os << "Greska: Nema tekuceg podatka.";
    }
};

template<typename T>
class Lista {

    struct Elem {
        Elem *sled;
        T info;

        Elem(const T &p, Elem *s = nullptr) {
            info = p;
            sled = s;
        }
    };

    Elem *prvi, *posl;
    mutable Elem *tek;

    void isprazni();

public:
    Lista() {
        prvi = posl = tek = nullptr;
    }

    Lista(const Lista &) = delete;

    ~Lista() {
        isprazni();
    }

    Lista &operator<<=(const T &t) {
        posl = (!prvi ? prvi : posl->sled) = new Elem(t);
        return *this;
    }

    Lista &operator>>=(const T &t) {
        if (!prvi) {
            prvi = posl = new Elem(t);
        } else {
            Elem *tmp = new Elem(t);
            tmp->sled = prvi;
            prvi = tmp;
        }
        return *this;
    }

    Lista &naPrvi() {
        tek = prvi;
        return *this;
    }

    const Lista &naPrvi() const {
        tek = prvi;
        return *this;
    }

    Lista &sledTek() {
        if (tek)tek = tek->sled;
        return *this;
    }

    const Lista &naSled() const {
        if (tek)tek = tek->sled;
        return *this;
    }

    bool postTek() const {
        return tek != nullptr;
    }

    T &dohvTek() {
        if (!tek) throw GNemaTek();
        return tek->info;
    }

    const T &dohvTek() const {
        if (!tek) throw GNemaTek();
        return tek->info;
    }

};

template<typename T>
void Lista<T>::isprazni() {
    while (prvi) {
        Elem *stari = prvi;
        prvi = prvi->sled;
        delete stari;
    }
    posl = tek = nullptr;
}


#endif //V_SABLONI_LISTA_H
