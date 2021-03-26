#include <iostream>
#include "stos.hpp"

stos::stos():
pojemnosc(1), ile(0) {
    tab = new string[pojemnosc];
}

stos::stos(int poj) {
    if(poj > 100) {
        cout << "Wrong capacity." << endl;
        return;
    }
    pojemnosc = poj;
    ile = 0;
    tab = new string[pojemnosc];

}

stos::stos(initializer_list<string> lista) {
    pojemnosc = lista.size();
    ile = 0;
    tab = new string[pojemnosc];
    for (auto s : lista)
        wloz(s);
}

stos::stos(stos&& s) {
    pojemnosc = s.pojemnosc;
    ile = s.ile;
    tab = s.tab;
    s.tab = nullptr;
}

stos::stos(const stos& s) {
    pojemnosc = s.pojemnosc;
    ile = 0;
    tab = new string[pojemnosc];

    for (int i = 0; i < s.ile; i++)
    {
        tab[i] = s.tab[i];
        ile++;
    }
}

stos & stos::operator=(stos& s) {
    pojemnosc = s.pojemnosc;
    ile = s.ile;
    tab = s.tab;
    s.tab = nullptr;
    return *this;
}

stos & stos::operator=(const stos& s) {
    pojemnosc = s.pojemnosc;
    ile = 0;
    tab = new string[pojemnosc];

    for (int i = 0; i < s.ile; i++)
    {
        tab[i] = s.tab[i];
        ile++;
    }
    return *this;
}

stos::~stos() {
    delete[](tab);
}

void stos::wloz(string s) {
    if(ile >= pojemnosc) {
        cout << "Maximum capacity reached. Can't put new words." << endl;
        return;
    }
    tab[ile] = s;
    ile++;
}

string stos::sciagnij() {
    ile--;
    return tab[ile];
}

string stos::sprawdz() {
    if(rozmiar() == 0) return "Empty.";
    return tab[ile-1];
}

int stos::rozmiar() {
    return ile;
}

stos stos::odwroc() {
    stos *s = new stos(pojemnosc);
    s->pojemnosc = pojemnosc;
    s->ile = 0;
    while(s->ile != ile) {
        s->tab[ile] = tab[ile - s->ile];
        s->ile++;
    }
    return *s;
}