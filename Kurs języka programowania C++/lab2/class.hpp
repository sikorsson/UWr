#ifndef INC_2_CLASS_HPP
#define INC_2_CLASS_HPP
class wektor {
public:
    double dx;
    double dy;
    wektor() = default;
    wektor(double dx, double dy);
    wektor(const wektor& w);
};

class punkt {
public:
    double x;
    double y;
    punkt() = default;
    punkt(double x, double y);
    punkt(punkt& p, wektor& w);
    punkt(const punkt& p);
};
class prosta {
    double a;
    double b;
    double c;
    void unormuj();
public:
    prosta(punkt& p1, punkt& p2);
    prosta(wektor& w);
    prosta(double a, double b, double c);
    prosta(prosta& p, wektor& w);
    prosta();
    bool rownlolegle(wektor& w);
    bool prostopadle(wektor& w);
    bool zawiera_punkt(punkt& p);
    double getA() const;
    double getB() const;
    double getC() const;
};

wektor zloz_wektory(wektor& w1, wektor& w2);
bool rownlolegle(prosta& p1, prosta& p2);
bool prostopadle(prosta& p1, prosta& p2);
punkt przeciecie(prosta& p1, prosta& p2);
#endif //INC_2_CLASS_HPP
