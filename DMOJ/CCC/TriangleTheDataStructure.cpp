// CCC '19 S5 - Triangle: The Data Structure

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
struct BIT2D {
    vector<vector<T>> bit;
    int n, m;

    BIT2D(int n, int m) {
        this->n = n;
        this->m = m;
        bit.assign(n, vector<T>(m, 0));
    }

    T query(int x, int y) {
        T ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret = max(ret, bit[i][j]);
        return ret;
    }

    void update(int x, int y, T val) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] = max(bit[i][j], val);
    }
};

const int MM = 3003;
int n, k, arr[MM][MM];
long long ans = 0;
int main() {
    // read input
    su(n);
    su(k);
    for (int i = 0; i < n; i++) {
        for (int j = n - 1 - i; j < n; j++) {
            su(arr[i][j]);
        }
    }
    BIT2D<int> bit(n, n);
    // fill initial triangle
    for (int i = n - k + 1, dep = 1; i < n; i++, dep++) {
        for (int j = n - 1; j >= n - dep; j--) {
            bit.update(i, j, arr[i][j]);
        }
    }
    // fill 1 by 1
    for (int start = n - k; start >= 0; start--) {
        for (int i = start, j = n - 1, dep = 1; i < n; i++, j--, dep++) {
            bit.update(i, j, arr[i][j]);
            if (dep >= k){
                ans += bit.query(i, j + k - 1);
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
