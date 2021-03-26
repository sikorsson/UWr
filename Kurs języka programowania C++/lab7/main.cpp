#include <iostream>
#include "wymierna.hpp"

using namespace std;
using namespace obliczenia;

int main() {
    obliczenia::wymierna a(1, 3);
    cout << a;
    obliczenia::wymierna b(2);
    obliczenia::wymierna c(1, 2);
    cout << b + c;
    obliczenia::wymierna d(5);
    obliczenia::wymierna e(2);
    cout << d + e;
    obliczenia::wymierna f(22, 7);
    cout << f;
    obliczenia::wymierna g(10, 0);
    return 0;
}