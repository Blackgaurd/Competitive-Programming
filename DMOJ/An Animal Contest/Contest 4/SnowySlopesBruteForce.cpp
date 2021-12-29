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
unordered_set<pii, pair_hash> slopes;
vector<pii> arr;
void apply_gcd(pii &a) {
    int _gcd = gcd(abs(a.first), abs(a.second));
    a.first /= _gcd;
    a.second /= _gcd;
}
pii slope(pii &first, pii &second){
    return {first.second - second.second, first.first - second.first};
}
int main() {
    su(n);
    su(m);
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        su(arr[i].first);
        su(arr[i].second);
    }
    for (int i = 0; i < m; i++) {
        pii tmp;
        si(tmp.first);
        si(tmp.second);
        apply_gcd(tmp);
        slopes.insert(tmp);
        slopes.insert({-tmp.first, -tmp.second});
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            pii cur = slope(arr[i], arr[j]);
            apply_gcd(cur);
            if (slopes.find(cur) != slopes.end()){
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}