#include "Kugla.h"

using namespace std;

int main() {

    try {
        Lista<Kugla *> l;

        Boja p(25, 63, 45);
        Boja p1(63, 36, 245);
        Boja p2(43, 26, 75);
        Boja p3(12, 46, 163);
        Boja p4(26, 146, 111);

        Kugla k1(Kugla::MALA, 15, p);
        Kugla k2(Kugla::VELIKA, 35, p1);
        Kugla k3(Kugla::VELIKA, 75, p2);
        Kugla k4(Kugla::SREDNJA, 236, p3);
        Kugla k5(Kugla::NAJVECA, 135, p4);

        l <<= &k1;
        l <<= &k2;
        l <<= &k3;
        l <<= &k4;
        l >>= &k5;

        bool t = p1 == p;
        cout << t << endl;

        cout << p1 + p2 << endl;

        for (l.naPrvi(); l.postTek(); l.sledTek()) {
            cout << *l.dohvTek() << endl;
        }
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}
