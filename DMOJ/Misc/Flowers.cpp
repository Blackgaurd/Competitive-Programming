// Flowers

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
            bit[ind] = max(bit[ind], val);
            ind |= (ind + 1);
        }
    }

    T query(int r) {
        T ret = 0;
        while (r >= 0) {
            ret = max(ret, bit[r]);
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }
};

int n;
ll ans = 0;
int main(){
    su(n);
    vector<int> arr(n);
    BIT<ll> bit(n + 1);
    for (int i=0; i<n; i++) su(arr[i]);
    for (int i=0; i<n; i++){
        ll a;
        su(a);
        a += bit.query(arr[i]);
        bit.add(arr[i], a);
        ans = max(a, ans);
    }
    printf("%lld\n", ans);

    return 0;
}