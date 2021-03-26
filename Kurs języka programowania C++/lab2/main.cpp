#include <iostream>
#include "class.hpp"
using namespace std;

int main() {
    wektor w1(8, 3);
    wektor w2(2, 1);
    punkt p1(1, 1);
    punkt p2(p1, w1);
    punkt p3(21, 21);
    punkt p4(-5, -6);
    prosta l1(w1);
    prosta l2(-4, 2, 10);
    prosta l3(p1, p2);
    prosta l4(0.25, 1, 0);
    prosta l5(l2, w2);
    prosta linia(-3, 1, 0);
    try
    {
        prosta linia(p1, p1);
    }
    catch (invalid_argument inv)
    {
        cerr << inv.what() << endl;
    }
    wektor w3 = zloz_wektory(w1, w2);
    punkt p5 = przeciecie(l2, l4);
    cout << linia.prostopadle(w1) << endl;
    cout << linia.prostopadle(w2) << endl;
    cout << linia.rownlolegle(w1) << endl;
    cout << linia.rownlolegle(w2) << endl;
    cout << linia.zawiera_punkt(p3) << endl;
    cout << linia.zawiera_punkt(p4) << endl;
    cout << l3.getA() << "x + " << l3.getB() << "y + " << l3.getC() << " = 0" << endl;
    cout << prostopadle(l2, l1) << endl;
    cout << prostopadle(l2, l4) << endl;
    cout << rownlolegle(l2, l5) << endl;
    cout << rownlolegle(l2, l4) << endl;
    return 0;
}
