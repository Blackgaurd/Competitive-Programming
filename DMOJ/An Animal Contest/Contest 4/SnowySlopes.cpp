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
#define contains(key) (seen.find(key) != seen.end())
typedef pair<long long, long long> pii;

struct pair_hash {
    template <typename T1, typename T2>
    size_t operator()(pair<T1, T2> const &pair) const {
        size_t h1 = hash<T1>()(pair.first);
        size_t h2 = hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};
int n, m, ans;
unordered_set<pii, pair_hash> seen;
vector<pii> arr, slopes;
void apply_gcd(pii &a){
    int _gcd = gcd(abs(a.first), abs(a.second));
    a.first /= _gcd;
    a.second /= _gcd;
}
int main() {
    #ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    su(n);
    su(m);
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        su(arr[i].first);
        su(arr[i].second);
    }
    slopes.resize(2 * m);
    for (int i = 0; i < m; i++) {
        si(slopes[i].second);
        si(slopes[i].first);
        slopes[i + m].first = -slopes[i].first;
        slopes[i + m].second = -slopes[i].second;
        apply_gcd(slopes[i]);
        apply_gcd(slopes[i + m]);
    }
    for (auto p : arr) {
        cout << "cur: " << p.first << ' ' << p.second << '\n';
        if (!seen.empty()) {
            for (auto s : slopes) {
                pii needed = {s.first + p.first, s.second + p.second};
                if (p == pii(4, 4) && (s == pii(-1, 1) || s == pii(1, -1))) cout << "needed: " << needed.first << ' ' << needed.second << '\n';
                apply_gcd(needed);
                if (seen.find(needed) == seen.end()) continue;
                cout << "FOUND!!!!!\n" << p.first << ' ' << p.second << ", " << needed.first << ' ' << needed.second << ", " << s.first << ' ' << s.second << '\n';
            }
        }
        seen.insert(p);
    }
    for (auto [x, y]: seen) cout << x << ' ' << y << '\n';
    printf("%d\n", ans);

    return 0;
}