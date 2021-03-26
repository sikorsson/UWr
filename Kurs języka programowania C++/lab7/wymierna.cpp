#include "wymierna.hpp"

obliczenia::wymierna::wymierna() = default;
obliczenia::wymierna::wymierna(int l, int m) {
    if (m == 0) throw dzielenie_przez_0("Mianownik jest rowny 0");
    licz = l;
    mian = m;
    format();
}
obliczenia::wymierna::wymierna(int n):
licz(n), mian(1) {}
obliczenia::wymierna::wymierna(const wymierna &w) {
    this->licz = w.licz;
    this->mian = w.mian;
}
obliczenia::wymierna::~wymierna() = default;

void obliczenia::wymierna::format() {
    int tmp, sign;
    sign = (licz < 0) ^ (mian < 0) ? -1 : 1;
    tmp = nwd(licz, mian);
    licz = (licz / tmp) * sign;
    mian = (mian / tmp) * sign;
}

int obliczenia::wymierna::nwd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int obliczenia::wymierna::getLicz() {
    return licz;
}
int obliczenia::wymierna::getMian() {
    return mian;
}

obliczenia::wymierna obliczenia::wymierna::operator+(const wymierna &w) {
    int nww, mult_this, mult_w;
    nww = (this->mian * w.mian) / nwd(this->mian, w.mian);
    mult_this = nww / this->mian;
    mult_w = nww / w.mian;
    this->licz = this->licz * mult_this + w.licz * mult_w;
    this->mian = this->mian * mult_this;
    return wymierna(this->licz, this->mian);
}
obliczenia::wymierna obliczenia::wymierna::operator-(const wymierna &w) {
    int nww, mult_this, mult_w;
    nww = (this->mian * w.mian) / nwd(this->mian, w.mian);
    mult_this = nww / this->mian;
    mult_w = nww / w.mian;
    this->licz = this->licz * mult_this - w.licz * mult_w;
    this->mian = this->mian * mult_this;
    return wymierna(this->licz, this->mian);
}
obliczenia::wymierna obliczenia::wymierna::operator*(const wymierna &w) {
    this->licz = this->licz * w.licz;
    this->mian = this->mian * w.mian;
    return wymierna(this->licz, this->mian);
}
obliczenia::wymierna obliczenia::wymierna::operator/(const wymierna &w) {
    this->licz = this->licz * w.mian;
    this->mian = this->mian * w.licz;
    return wymierna(this->licz, this->mian);
}
obliczenia::wymierna obliczenia::wymierna::operator-() {
    this->licz = -this->licz;
    return wymierna(this->licz, this->mian);
}
obliczenia::wymierna obliczenia::wymierna::operator!() {
    int tmp;
    tmp = this->licz;
    this->licz = this->mian;
    this->mian = tmp;
    return wymierna(this->licz, this->mian);
}
obliczenia::wymierna::operator double() {
    return (double)licz / (double)mian;
}
obliczenia::wymierna::operator int() {
    return round((double)licz / (double)mian);
}