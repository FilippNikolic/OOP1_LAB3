#include "Domaci.h"
#include "Strani.h"

int main() {


    try{
        // isprobavanje liste
        Lista<int *> l;
        int i = 2, j = 4, k = 8, m = 12, n = 63;
        l += &i;
        l += &n;
        l += &k;
        l += &m;
        l += &j;

        cout << l << endl;

        cout << *l[2] << endl;

        *l[2] = 5;

        cout << *l[2] << endl << endl;

        cout << l << endl;

        Lista<int *> l1(l);

        cout << l1 << endl;

        //isprobavanje vremena

        Vreme v(0, 1);
        Vreme v1(2, 4);

        cout << (v1 > v) << endl;

        cout << (v1 + v) << endl;

        //ISPROBAVANJE FILMOVA

        Domaci d1("Avatar", v1);

        d1.oceniFilm(3);
        d1.oceniFilm(7);
        d1.oceniFilm(10);

        cout << d1 << endl;

        Strani s1("Bosna", "KO ZNA ZNA", v, Strani::SINHRONIZOVAN);

        s1.oceniFilm(5);
        s1.oceniFilm(1);
        s1.oceniFilm(8);

        cout << s1 << endl;
    }
    catch (exception& e){
        cout << e.what() << endl;
    }



    return 0;
}
