// Checkerboard Summation (Hard)

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

    BIT2D(vector<vector<T>> &arr) : BIT2D(arr.size(), arr[0].size()) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) add(i, j, arr[i][j]);
    }

    T sum(int x, int y) {
        T ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, T val) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1)) bit[i][j] += val;
    }

    T sum(int x1, int y1, int x2, int y2) {
        x1--;
        y1--;
        return sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);
    }

    T get(int x, int y) { return sum(x, y, x, y); }

    void change(int x, int y, int val) { add(x, y, val - get(x, y)); }
};

int m, n;
char c;
bool black(int a, int b) { return !((a + b) & 1); }
int main() {
    su(m);
    su(n);
    BIT2D<int> bit(m + 1, n + 1);
    while (true) {
        sc(c);
        if (c == '0') break;
        if (c == '1') {
            int r, c, x;
            su(r);
            su(c);
            si(x);
            bit.change(r, c, (black(r, c) ? x : -x));
        } else {
            int r1, c1, r2, c2, ans;
            su(r1);
            su(c1);
            su(r2);
            su(c2);
            ans = bit.sum(r1, c1, r2, c2);
            printf("%d\n", (black(r1, c1) ? ans : -ans));
        }
    }

    return 0;
}