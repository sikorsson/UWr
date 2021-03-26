#include "manipulatory.hpp"

auto &manipulatory::clearline(istream &in) {
    string s;
    getline(in, s);
    return in;
}

manipulatory::ignore::ignore(int x) {
    this->x = x;
}

auto &manipulatory::comma(ostream &out) {
    return out << ", ";
}
auto &manipulatory::colon(ostream &out) {
    return out << ": ";
}

manipulatory::index::index(int x, int w) {
    this->x = x;
    this->w = w;
}

void manipulatory::print(vector <string> v) {
    sort(v.begin(), v.end());
    int i = 0;
    while(i != v.size()) {
        cout << manipulatory::index(i, i + 1) << manipulatory::colon << v[i] << manipulatory::comma << endl;
        i++;
    }
}
