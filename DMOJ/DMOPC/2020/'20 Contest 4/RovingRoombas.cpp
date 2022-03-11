// DMOPC '20 Contest 4 P3 - Roving Roombas

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
int n, m;
long long ans;
struct pt {
    int x, y, t;
};
vector<pt> events;
map<int, int> coord;
int main() {
    // input
    su(n);
    su(m);
    for (int i = 0, x, y; i < n; i++) {
        su(x);
        su(y);
        events.push_back({x, y, 1});
        coord[y] = 0;
    }
    for (int i = 0, x, y; i < m; i++) {
        su(x);
        su(y);
        events.push_back({x, y, 0});
        coord[y] = 0;
    }

    // sort events by x
    // horizontal ones come first
    sort(events.begin(), events.end(), [](pt &a, pt &b) {
        return a.x == b.x ? a.t < b.t : a.x < b.x;
    });

    // coord compress
    int idx = 1;
    for (auto &p : coord) {
        p.second = idx++;
    }

    // inversion
    BIT<int> bit(idx);
    for (auto [x, y, t] : events) {
        if (t == 1) bit.update(coord[y], 1);
    }
    for (auto [x, y, t] : events) {
        if (t == 1) {
            bit.update(coord[y], -1);
        } else {
            ans += bit.query(coord[y]);
        }
    }
    printf("%lld\n", ans);
}