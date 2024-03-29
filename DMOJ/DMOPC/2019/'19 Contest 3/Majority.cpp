// DMOPC '19 Contest 3 P3 - Majority

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
        if (l <= 0)
            return sum(r);
        return sum(r) - sum(l - 1);
    }
};

const int MM = 15e4 + 3;
int n, arr[MM];
long long ans = 0;
BIT<long long> bit(2 * MM);
int main() {
    su(n);
    bit.add(n + 1, 1);
    for (int i = 1, a; i <= n; i++) {
        su(a);
        arr[i] = (a == 1 ? 1 : -1);
        arr[i] += arr[i - 1];
        int shift = arr[i] + n + 1;
        ans += bit.sum(shift - 1);
        bit.add(shift, 1);
    }
    printf("%lld\n", ans);

    return 0;
}