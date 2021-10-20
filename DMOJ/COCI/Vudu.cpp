// COCI '15 Contest 2 #5 Vudu

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
};

const int MM = 1e6 + 3;
int n, p;
ll ans = 0, psa[MM];
int main() {
    su(n);
    for (int i = 1; i <= n; i++) su(psa[i]);
    su(p);
    vector<ll> cop(n + 1);
    for (int i = 1; i <= n; i++) {
        psa[i] += psa[i - 1] - p;
        cop[i] = psa[i];
    }
    sort(cop.begin(), cop.end());
    BIT<int> bit(n + 1);
    for (int i = 0; i <= n; i++) {
        int cur = lower_bound(cop.begin(), cop.end(), psa[i]) - cop.begin();
        ans += bit.sum(cur);
        bit.add(cur, 1);
    }
    printf("%lld\n", ans);

    return 0;
}