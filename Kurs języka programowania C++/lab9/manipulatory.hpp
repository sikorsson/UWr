#ifndef INC_9_MANIPULATORY_HPP
#define INC_9_MANIPULATORY_HPP

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

namespace manipulatory {
    auto &clearline(istream &in);

    class ignore {
    public:
        int x;
        ignore(int x);
        friend auto &operator>>(istream &in, const ignore &ig) {
            int i = ig.x;
            while(i > 0 && in.get() != '\n' && in)
                i--;
            return in;
        }
    };

    auto &comma(ostream &out);
    auto &colon(ostream &out);

    class index {
    public:
        int x;
        int w;
        index(int x, int w);
        friend auto &operator<<(ostream &out, const index &ix) {
            out << "[";
            out.width(ix.w);
            out << ix.x << "]";
            return out;
        }
    };

    void print(vector <string> v);
}

#endif //INC_9_MANIPULATORY_HPP
