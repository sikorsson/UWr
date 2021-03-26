#include <iostream>
using namespace std;

void sito(bool *tab, unsigned int n)
{
    for (int i=2; i*i<=n; i++)
    {
        if(!tab[i])
            for (int j = i*i ; j<=n; j+=i)
                tab[j] = true;
    }
}

bool sito_init(int n) {
    bool *tab;
    tab = new bool [n + 1];
    for(int i = 2; i <= n; i++)
        tab[i] = false;
    sito(tab, n);
    if(!tab[n]){
        delete []tab;
        return true;
    }
    else{
        delete []tab;
        return false;
    }
}

int main(int argc, char *argv[]) {
    if(argc == 1) {
        cerr<<"Brak argumentow. Podaj parametry.";
        return 0;
    }
    int n;
    int64_t x;
    cin >> n;

    for(int i = 0; i<n; i++) {
        cin >> x;
        cout << x << " = ";
        if (x == 0) cout << "0\n";
        else {

            if (x < 0) {
                cout << "-1 * ";
                x *= -1;
            }
            if (sito_init(x)) cout << x << "\n";
            else {
                int t = 2;
                bool first = true;
                while(x != 1) {
                    while(x % t == 0) {
                        x /= t;
                        if (first) {
                            first = false;
                            cout << t;
                        }
                        else cout << " * " << t;
                    }
                    t += 1;
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}
