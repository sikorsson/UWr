#ifndef INC_7_WYMIERNA_HPP
#define INC_7_WYMIERNA_HPP
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <map>
#include "wyjatek_wymierny.hpp"

using namespace std;

namespace obliczenia {
    class wymierna {
    private:
        int licz, mian;
    public:
        wymierna();
        wymierna(int l, int m);
        wymierna(int n);
        wymierna(const wymierna &w);
        ~wymierna();

        void format();

        int nwd(int a, int b);

        int getLicz();
        int getMian();

        wymierna operator+(const wymierna &w);
        wymierna operator-(const wymierna &w);
        wymierna operator*(const wymierna &w);
        wymierna operator/(const wymierna &w);
        wymierna operator-();
        wymierna operator!();
        operator double();
        operator int();
        friend ostream &operator<<(ostream &s, wymierna w) { //https://www.geeksforgeeks.org/represent-the-fraction-of-two-numbers-in-the-string-format/
            int num = w.licz;
            int den = w.mian;
            if (num == 0)
                return s << "0\n";
            int sign = (num < 0) ? -1 : 1;
            num = abs(num);
            int initial = num / den;
            string res;
            if (sign == -1)
                res += "-";
            res += to_string(initial);
            if (num % den == 0)
                return s << res << "\n";
            res += ".";
            int rem = num % den;
            map<int, int> mp;
            int index;
            bool repeating = false;
            while (rem > 0 && !repeating) {
                if (mp.find(rem) != mp.end()) {
                    index = mp[rem];
                    repeating = true;
                    break;
                }
                else
                    mp[rem] = res.size();
                rem = rem * 10;
                int temp = rem / den;
                res += to_string(temp);
                rem = rem % den;
            }
            if (repeating) {
                res += ")";
                res.insert(index, "(");
            }
            return s << res << "\n";
        }
    };
}

#endif //INC_7_WYMIERNA_HPP
