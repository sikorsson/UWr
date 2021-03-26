#ifndef INC_9_PLIKI_HPP
#define INC_9_PLIKI_HPP

#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;

namespace manipulatory {

    template <typename T>
    class wejscie
    {
        ifstream in;
    public:
        explicit wejscie(string file) {
            //this->in.exceptions(ios_base::badbit | ios_base::failbit);
            this->in.open(file, ios::binary);

            vector<T> bytes;
            T byte;

            while (in)
            {
                byte = this->in.get();
                bytes.push_back(byte);
            }
            for (auto byte : bytes)
                cout << byte << endl;
            cout << endl;
        }
        ~wejscie() {
            in.close();
        }
        bool eof() {
            return in.peek() == EOF;
        }
    };

    template <typename T>
    class wyjscie
    {
        ofstream out;
    public:
        explicit wyjscie(string file, T val) {
            this->out.exceptions(ios_base::badbit | ios_base::failbit);
            this->out.open(file, ios::binary);
            this->out.write((char *) &val, sizeof(val));
        }
        ~wyjscie() {
            this->out.close();
        }
    };
}

#endif //INC_9_PLIKI_HPP
