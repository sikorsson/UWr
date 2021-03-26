#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int binarySearch(vector<pair<long long, unsigned int>> &v, int l, int r, long long key) {
    while (r >= l && key >= v[l].first && key <= v[r].first) {
        int s = l + (r - l) / 2;
        if (v[s].first == key)
            return s;
        if (v[s].first > key)
            r = s - 1;
        else
            l = s + 1;
    }
    return -1;
}

int main() {
    vector<pair<long long, unsigned int>> v;
    unsigned int m, n;
    long long d, res = 0;
    scanf("%d", &m);
    v.reserve(m);
    for (int i = 0; i < m; i++) {
        scanf("%lld %d", &d, &n);
        v.emplace_back(d, n);
    }
    sort(v.begin(), v.end(), [](auto &x, auto &y) {return x.first < y.first;});

    //for(pair<long long, unsigned int> x: v) {cout<<x.first<<" "<<x.second<<'\n';}

    for (int i = 0; i < v.size(); i++) {
        if(v[i].second == 0) continue;
        while(v[i].second != 0) {
            if(v[i].second & 1) {
                v[i].second--;
                res++;
            }
            else {
                v[i].first <<= 1;
                v[i].second >>= 1;
                unsigned int index = binarySearch(v, i + 1, v.size() - 1, v[i].first);
                if (~index) {
                    v[i].second += v[index].second;
                    v[index].second = 0;
                }
            }
        }
    }
    printf("%lld", res);
    return 0;
}