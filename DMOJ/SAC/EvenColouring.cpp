// SAC '22 Code Challenge 2 P5 - Even Colouring

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
typedef long long ll;

template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int size) {
        n = size;
        bit.assign(n, 0);
    }

    void update(int ind, T val) {
        while (ind < n) {
            bit[ind] += val;
            ind |= (ind + 1);
        }
    }

    T query(int r) {
        T ret = 0;
        while (r >= 0) {
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }

    T query(int l, int r) {
        if (l <= 0) return query(r);
        return query(r) - query(l - 1);
    }
};
int n, q, arr[int(1e6 + 3)];
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(q);
    BIT<ll> even(n + 1), odd(n + 1);
    for (int i = 1; i <= n; i++) {
        si(arr[i]);
        if (i & 1)
            odd.update(i, arr[i]);
        else
            even.update(i, arr[i]);
    }
    while (q--) {
        char c;
        sc(c);
        int a, b;
        su(a);
        si(b);
        auto &cur = a & 1 ? odd : even;
        if (c == '1') {
            cur.update(a, -arr[a] + b);
            arr[a] = b;
        } else {
            printf("%lld\n", cur.query(a, b));
        }
    }

    return 0;
}