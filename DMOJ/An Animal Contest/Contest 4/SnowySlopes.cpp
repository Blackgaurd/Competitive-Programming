// An Animal Contest 4 P3 - Snowy Slopes

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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct pair_hash {
    template <typename T1, typename T2>
    size_t operator()(pair<T1, T2> const &pair) const {
        size_t h1 = hash<T1>()(pair.first);
        size_t h2 = hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};
int n, m;
ll ans;
vector<pii> coords;
unordered_set<pll, pair_hash> slopes;
unordered_map<ll, int> seen;
pll gcd(pll cur) {
    ll _gcd = gcd(abs(cur.first), abs(cur.second));
    cur.first /= _gcd;
    cur.second /= _gcd;
    if (cur.first < 0 && cur.second > 0) {
        cur.first *= -1;
        cur.second *= -1;
    }
    return cur;
}
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(m);
    coords.resize(n);
    for (int i = 0; i < n; i++) {
        su(coords[i].first);
        su(coords[i].second);
    }
    for (int i = 0; i < m; i++) {
        pll cur;
        si(cur.first);
        si(cur.second);
        cur = gcd(cur);
        slopes.insert(cur);
    }
    for (auto [k, d] : slopes) {
        for (auto [x, y] : coords) {
            ll cur = k * x - d * y;
            ans += seen[cur]++;
        }
        seen.clear();
    }
    printf("%lld\n", ans);

    return 0;
}