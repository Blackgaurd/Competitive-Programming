// DMOPC '16 Contest 1 P5 - Blood Tubes

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
long long n, a, ans;
int main() {
    su(n);
    BIT<int> bit(n + 1);
    for (int i = 0; i < n; i++) {
        su(a);
        int lt = bit.query(a);
        int gt = i - lt;
        ans += min(lt, gt);
        bit.update(a, 1);
    }
    printf("%lld\n", ans);
}