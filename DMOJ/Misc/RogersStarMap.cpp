// Roger's Star Map

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
};
int n, lvl[15003];
vector<pii> arr;
int main() {
    #ifdef PC
    freopen("RogersStarMap.in", "r", stdin);
    freopen("RogersStarMap.out", "w", stdout);
    #endif
    su(n);
    arr.resize(n);
    for (auto &[a, b] : arr) {
        su(a);
        su(b);
    }
    sort(arr.begin(), arr.end());
    BIT<int> bit(32003);
    for (auto [x, y] : arr) {
        lvl[bit.query(y)]++;
        bit.update(y, 1);
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", lvl[i]);
    }
}