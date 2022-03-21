// 2D Binary Indexed Tree

#include <bits/stdc++.h>
using namespace std;

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
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) ret += bit[i][j];
        return ret;
    }
    void update(int x, int y, T val) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1)) bit[i][j] += val;
    }
    T query(int x1, int y1, int x2, int y2) {
        x1--;
        y1--;
        return query(x2, y2) - query(x1, y2) - query(x2, y1) + query(x1, y1);
    }
};
