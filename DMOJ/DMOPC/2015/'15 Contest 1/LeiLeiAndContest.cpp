// DMOPC '15 Contest 1 P6 - Lelei and Contest
// imagine using seg tree lol

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
#define last(x) (x & (-x))
    vector<T> b1, b2;
    int n;

    BIT(int n) {
        this->n = n;
        b1.resize(n);
        b2.resize(n);
    }
    T query(const vector<T> &arr, int b) {
        T ret = 0;
        for (; b; b -= last(b)) ret += arr[b];
        return ret;
    }
    // sum [1..b]
    T query(int b) {
        return query(b1, b) * b - query(b2, b);
    }
    // sum [i..j]
    T query(int i, int j) {
        return query(j) - query(i - 1);
    }
    void update(vector<T> &arr, int ind, T val) {
        for (; ind <= n; ind += last(ind)) arr[ind] += val;
    }
    // [i..j] += val
    void update(int i, int j, T val) {
        update(b1, i, val);
        update(b1, j + 1, -val);
        update(b2, i, val * (i - 1));
        update(b2, j + 1, -val * j);
    }
    // [ind] += val
    void update(int ind, T val) {
        update(ind, ind, val);
    }
};

int n, q, MOD;
int main() {
    su(MOD);
    su(n);
    su(q);
    BIT<long long> bit(n + 3);
    for (int i = 1, val; i <= n; i++) {
        su(val);
        bit.update(i, val);
    }
    while (q--) {
        char c;
        sc(c);
        if (c == '2') {
            int l, r;
            su(l);
            su(r);
            printf("%lld\n", bit.query(l, r) % MOD);
        } else {
            int l, r, val;
            su(l);
            su(r);
            su(val);
            bit.update(l, r, val);
        }
    }

    return 0;
}
