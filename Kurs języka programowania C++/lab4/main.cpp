#include <iostream>
#include <stdlib.h>
#include "stos.hpp"

using namespace std;

int main() {
    int n = 0;
    string t;
    stos *s = new stos(50);
    while(n != 4) {
        system("cls");
        cout << "1. Wypisz element" << endl;
        cout << "2. Dodaj element" << endl;
        cout << "3. Usun element" << endl;
        cout << "4. Wyjdz" << endl;
        cin >> n;
        getchar();
        switch(n) {
            case 1:
                system("cls");
                cout << s->sprawdz() << endl;
                break;
            case 2:
                system("cls");
                cout << "Jakie zdanie chcesz dodac?" << endl;
                getline(cin, t);
                s->wloz(t);
                break;
            case 3:
                system("cls");
                cout << "Zdanie " << s->sciagnij() << " zdjete ze stosu" << endl;
                break;
            case 4:
                system("cls");
                break;
            default:
                system("cls");
                break;
        }
    }
    return 0;
}
