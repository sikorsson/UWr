#include <iostream>
#include "lista.hpp"
#include "lista.cpp"

using namespace std;

int main() {
    list<int> lista;
    lista.pushBack(1);
    lista.pushBack(2);
    lista.pushBack(3);
    lista.pushBack(4);
    lista.pushBack(5);
    cout << lista;
    list<int> l = list<int>(lista);
    cout << l;
    lista.pushBack(6);
    cout << lista;
    cout << l;
    return 0;
}
