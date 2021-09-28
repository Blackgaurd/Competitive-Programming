// CCC '05 S5 - Pinball Ranking

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on
typedef pair<int, int> pii;

template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int size) {
        n = size;
        bit.assign(n, 0);
    }

    BIT(vector<T> &arr) : BIT(arr.size()) {
        for (int i = 0; i < n; i++) {
            add(i, arr[i]);
        }
    }

    void add(int ind, T val) {
        while (ind < n) {
            bit[ind] += val;
            ind |= (ind + 1);
        }
    }

    T get(int ind) {
        if ((ind & 1) == 0) return bit[ind];
        return sum(ind, ind);
    }

    void set(int ind, T val) { add(ind, val - get(ind)); }

    T sum(int r) {
        T ret = 0;
        while (r >= 0) {
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }

    T sum(int l, int r) {
        if (l <= 0) return sum(r);
        return sum(r) - sum(l - 1);
    }
};

long long t, ttl = 0;
vector<int> arr;
map<int, int> mp;
int main() {
    su(t);
    BIT<int> bit(t);
    for (int i = 0; i < t; i++) {
        int a;
        su(a);
        arr.push_back(a);
        mp[a] = 0;
    }
    int cop = t;
    for (pii p : mp) {
        mp[p.first] = cop--;
    }
    for (int i : arr) {
        bit.add(mp[i], 1);
        ttl += bit.sum(mp[i] - 1) + 1;
    }
    printf("%.2f\n", double(ttl) / t);

    return 0;
}