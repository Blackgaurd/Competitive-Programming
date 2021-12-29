// sparse table

#include <bits/stdc++.h>
using namespace std;

int qlog2(int x) {
    return 31 - __builtin_clz(x);
}
int qlog2(long long x) {
    return 63 - __builtin_clzll(x);
}
template <typename T>
struct Sparse {
#define func min
    int n;
    vector<vector<T>> sparse;

    Sparse(vector<T> &arr) {
        n = arr.size();
        sparse.assign(qlog2(n) + 1, vector<T>(n + 1, 0));
        for (int i = 0; i < n; i++) sparse[i][0] = arr[i];
        for (int j = 1; j <= qlog2(n); j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                sparse[i][j] = func(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
    }
    T query(int l, int r) {
        int j = qlog2(r - l + 1);
        return func(sparse[l][j], sparse[r - (1 << j) + 1][j]);
    }
};