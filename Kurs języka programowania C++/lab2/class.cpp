#include "class.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
//wzory matematyczne odośnie: prostopadłe, równoległe, przecięcie itd. wzięte z wikipedii

wektor::wektor(double dx, double dy) {
    this->dx = dx;
    this->dy = dy;
}
wektor::wektor(const wektor& w) {
    this->dx = w.dx;
    this->dy = w.dy;
}

punkt::punkt(double x, double y) {
    this->x = x;
    this->y = y;
}
punkt::punkt(punkt& p, wektor& w) {
    this->x = p.x + w.dx;
    this->y = p.y + w.dy;
}
punkt::punkt(const punkt& p) {
    this->x = p.x;
    this->y = p.y;
}

double prosta::getA() const {
    return a;
}
double prosta::getB() const {
    return b;
}
double prosta::getC() const {
    return c;
}
void prosta::unormuj() {
    double sq = sqrt((a * a) + (b * b));
    if (!sq)
        throw invalid_argument ("Nie mozna utworzyc linii");
    double tmp = (c >= 0 ? 1 : -1) / sq;
    a *= tmp;
    b *= tmp;
    c *= tmp;
}
prosta::prosta(punkt& p1, punkt& p2) {
    if (p1.x == p2.x && p1.y == p2.y)
        throw invalid_argument ("Nie mozna utworzyc linii");
    if (p1.x == p2.x)
    {
        this->a = 1;
        this->b = 0;
        this->c = p1.x;
    }
    else
    {
        double a = (p2.y - p1.y) / (p2.x - p1.x);
        double b = p1.y - a * (p1.x);
        this->a = -a;
        this->b = 1;
        this->c = -b;
        unormuj();
    }
}
prosta::prosta(wektor& w) {
    if (w.dx == w.dy && !w.dx)
    {
        throw invalid_argument ("Nie mozna utworzyc linii");
    }
    punkt tmp(w.dx, w.dy);
    double x = w.dx / w.dy;

    x = -1 / x;
    this->c = -(tmp.y - x * tmp.x);
    this->b = 1;
    this->a = -x;
    unormuj();
}
prosta::prosta(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
    unormuj();
}
prosta::prosta(prosta& p, wektor& w) {
    this->a = p.a;
    this->b = p.b;
    this->c = p.c - (p.a * w.dx) - w.dy;
    unormuj();
}
bool prosta::rownlolegle(wektor& w) {
    if (w.dx == 0 && w.dy == 0)
        return true;

    double x = w.dx / w.dy;
    double y = -a / b;
    if(x == y) return true;
    else return false;
}
bool prosta::prostopadle(wektor& w) {
    if (w.dx == 0 && w.dy == 0)
        return true;
    double x = w.dx / w.dy;
    double y = -a / b;
    if(x * y == -1.0) return true;
    else return false;
}
bool prosta::zawiera_punkt(punkt& p) {
    if((a * p.x + b * p.y + c) == 0) return true;
    else return false;
}

wektor zloz_wektory(wektor& w1, wektor& w2) {
    double dx, dy;
    dx = w1.dx + w2.dx;
    dy = w1.dy + w2.dy;
    wektor w;
    w.dx = dx;
    w.dy = dy;
    return w;
}
bool rownlolegle(prosta& p1, prosta& p2) {
    if(((p1.getA() * p2.getB()) - (p2.getA() * p1.getB())) == 0) return true;
    else return false;
}
bool prostopadle(prosta& p1, prosta& p2) {
    if(((p1.getA() * p2.getA()) + (p1.getB() * p2.getB())) == 0) return true;
    else return false;
}
punkt przeciecie(prosta& p1, prosta& p2) {
    double a1, a2, b1, b2, x, y;
    a1 = -p1.getA() / p1.getB();
    a2 = -p2.getA() / p2.getB();
    b1 = -p1.getC();
    b2 = -p2.getC();
    x = (b2 - b1) / (a1 - a2);
    y = a1 * x + b1;
    punkt tmp;
    tmp.x = x;
    tmp.y = y;
    return tmp;
}