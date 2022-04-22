// Range Max Query

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

int qlog2(int x) {
    return 31 - __builtin_clz(x);
}
template <typename T>
struct Sparse {
#define func max
    int n;
    vector<vector<T>> sparse;

    Sparse(vector<T> &arr) {
        n = arr.size();
        sparse.assign(qlog2(n) + 1, vector<T>(n + 1, 0));
        for (int i = 0; i < n; i++) sparse[0][i] = arr[i];
        for (int j = 1; j <= qlog2(n); j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                sparse[j][i] = func(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
    }
    T query(int l, int r) {
        int j = qlog2(r - l + 1);
        return func(sparse[j][l], sparse[j][r - (1 << j) + 1]);
    }
};
int n, m;
int main() {
    su(n);
    su(m);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        si(arr[i]);
    }
    Sparse<int> st(arr);
    while (m--) {
        int a, b;
        su(a);
        su(b);
        printf("%d\n", st.query(a - 1, b - 1));
    }
}