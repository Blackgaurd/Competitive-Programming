// DMOPC '18 Contest 4 P4 - Dr. Henri and Lab Data
// this look like Selective Cutting :thinkie:

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
typedef long long ll;

template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int size) {
        n = size;
        bit.assign(n, 0);
    }

    void add(int ind, T val) {
        while (ind < n) {
            bit[ind] += val;
            ind |= (ind + 1);
        }
    }

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

const int MM = 2e5 + 3;
int n, q;
ll psa[MM];
pii m[MM];
struct qry {
    int l, r, val, ind;
    ll ans;
} queries[MM];
int main() {
    su(n);
    su(q);
    for (int i = 0; i < n; i++) {
        su(m[i].first);
        m[i].second = i + 1;

        psa[i + 1] = m[i].first + psa[i];
    }
    for (int i = 0; i < q; i++) {
        su(queries[i].l);
        su(queries[i].r);
        su(queries[i].val);
        queries[i].ind = i + 1;
    }
    sort(m, m + n, greater<pii>());
    sort(queries, queries + q, [](qry &a, qry &b) { return a.val > b.val; });

    BIT<ll> bit(MM);
    for (int mp = 0, qp = 0; qp < q;) {
        while (mp < n && queries[qp].val <= m[mp].first) {
            bit.add(m[mp].second, m[mp].first);
            mp++;
        }
        ll ge = bit.sum(queries[qp].l, queries[qp].r);
        ll ttl = psa[queries[qp].r] - psa[queries[qp].l - 1];
        queries[qp].ans = 2 * ge - ttl;
        qp++;
    }

    sort(queries, queries + q, [](qry &a, qry &b) { return a.ind < b.ind; });
    for (int i = 0; i < q; i++) {
        printf("%lld\n", queries[i].ans);
    }
}
