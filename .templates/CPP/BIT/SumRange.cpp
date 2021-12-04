// seg tree overrated
// BIT with range updates
// creds: https://github.com/kartikkukreja/blog-codes/blob/master/src/Range%20Updates%20%26%20Range%20Queries%20with%20BIT.cpp

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT {
#define last(x) (x & (-x))
    vector<T> b1, b2;
    int n;

    BIT(int n) {
        this->n = n;
        b1.resize(n);
        b2.resize(n);
    }
    T query(const vector<T> &arr, int b) {
        T ret = 0;
        for (; b; b -= last(b)) ret += arr[b];
        return ret;
    }
    // sum [1..b]
    T query(int b) {
        return query(b1, b) * b - query(b2, b);
    }
    // sum [i..j]
    T query(int i, int j) {
        return query(j) - query(i - 1);
    }
    void update(vector<T> &arr, int ind, T val) {
        for (; ind <= n; ind += last(ind)) arr[ind] += val;
    }
    // [i..j] += val
    void update(int i, int j, T val) {
        update(b1, i, val);
        update(b1, j + 1, -val);
        update(b2, i, val * (i - 1));
        update(b2, j + 1, -val * j);
    }
    // [ind] += val
    void update(int ind, T val) {
        update(ind, ind, val);
    }
};
