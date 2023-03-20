//
// Created by nfili on 11/01/2023.
//

#ifndef ZADATAK2_FILM_H
#define ZADATAK2_FILM_H

#include <utility>

#include "Lista.h"
#include "Vreme.h"

using namespace std;

class Film  {

    Vreme vreme;
    string naziv;
    Lista<int> ocene;

protected:

    void pisi(ostream& os) const{
        os << naziv << " " << dohvVremeTrajanja() << " " << avgOcena();
    }

public:

    Film(string n, Vreme v) : vreme(v) {
        naziv = n;
    }

    virtual ~Film() {};

    Film& oceniFilm(int o) {
        ocene += o;
        return *this;
    }

    Vreme dohvVremeTrajanja() const {
        return this->vreme;
    }

    double avgOcena() const{
        double avg = 0;
        for (int i = 0; i < ocene.dohvBrPod(); i++) {
            avg += double(ocene[i]);
        }
        return avg / ocene.dohvBrPod();
    }

    virtual char dohvOznaku() = 0;

    string dohvNaziv() const{
        return naziv;
    }

    friend ostream &operator<<(ostream &os, Film &f) {
        f.pisi(os);
        return os;
    }

};


#endif //ZADATAK2_FILM_H
