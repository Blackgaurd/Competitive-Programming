// Binary Indexed Tree Test

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

template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int size) {
        n = size;
        bit.assign(n, 0);
    }

    BIT(vector<T> arr) : BIT(arr.size()) {
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

    T get(int ind) { return sum(ind, ind); }

    void set(int ind, T val) {
        add(ind, -get(ind));
        add(ind, val);
    }

    long long sum(int r) {
        T ret = 0;
        while (r >= 0) {
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }

    long long sum(int l, int r) {
        if (l <= 0) return sum(r);
        return sum(r) - sum(l - 1);
    }
};

const int MM = 1e5 + 3;
int n, m;
char c;
int main() {
    su(n);
    su(m);
    BIT<long long> bit(n), freq(MM);
    for (int i = 0, a; i < n; i++) {
        su(a);
        bit.add(i, a);
        freq.add(a, 1);
    }
    while (m--) {
        sc(c);
        if (c == 'C') {
            int ind, val;
            su(ind);
            su(val);
            ind--;
            int old = bit.get(ind);
            freq.add(old, -1);
            bit.add(ind, val - old);
            freq.add(val, 1);
        } else if (c == 'S') {
            int l, r;
            su(l);
            su(r);
            printf("%lld\n", bit.sum(l - 1, r - 1));
        } else {
            int a;
            su(a);
            printf("%lld\n", freq.sum(a));
        }
    }

    return 0;
}