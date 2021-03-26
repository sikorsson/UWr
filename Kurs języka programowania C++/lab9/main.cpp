#include <iostream>
#include <algorithm>
#include <vector>
#include "manipulatory.hpp"
#include "pliki.hpp"
using namespace std;

int main() {
    vector<string> v;
    int n;
    string s;

    cout << "Ignore '2':";
    cin >> manipulatory::ignore(2) >> s;
    cout << s << endl;

    cout << "Vector size:";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    manipulatory::print(v);

    manipulatory::wejscie<int> in("byte_test.txt");

    return 0;
}
