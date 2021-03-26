#ifndef INC_4_STOS_HPP
#define INC_4_STOS_HPP

using namespace std;

class stos {
private:
    int pojemnosc;
    int ile;
    string* tab = nullptr;
public:
    stos();
    stos(int poj);
    stos(initializer_list<string>);
    stos(stos&&);
    stos(const stos&);

    stos & operator=(stos&);
    stos & operator=(const stos&);

    ~stos();

    void wloz(string s);
    string sciagnij();
    string sprawdz();
    int rozmiar();
    stos odwroc();
};

#endif //INC_4_STOS_HPP
