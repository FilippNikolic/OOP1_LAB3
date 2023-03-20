#include "Skup.h"
#include "Rec.h"
#include "Stih.h"
#include "Katren.h"

int main() {

    Skup s("idegas");
    char p = 'm';
    s += p;

    Rec r("trn"), r1("gazdarica");
    cout << +r << endl;

    cout << ~r << endl;

    cout << r(-1) << endl;

    int z = r ^ r1;

    cout << z << endl;

    Rec r2;

    cin >> r2;

    cout << r2 << endl;

    Stih stih1, stih2;

    cin >> stih1;

    cin >> stih2;

    int t = stih1 ^ stih2;

    cout << t << endl;

    cout << stih1 << endl;


    cout << stih1[0] << endl;
    cout << stih1[2] << endl;
    cout << stih1[+stih1 - 1] << endl;

    stih1(2);

    cout << stih1 << endl;

    stih1(r, 1);

    cout << stih1 << endl;

    Katren strofa, strofa1;

    cin >> strofa;

    cout << strofa;

    strofa1 = strofa;

    int k = *strofa1;

    cout << k << endl;

    strofa(0, 2);

    cout << strofa << endl;

    cout << strofa[2] << endl << endl;

    -strofa;

    cout << strofa << endl;

    return 0;
}
