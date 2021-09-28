// 1D Binary Indexed Tree

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int size) {
        n = size;
        bit.assign(n, 0);
    }

    BIT(vector<T> &arr) : BIT(arr.size()) {
        for (int i = 0; i < n; i++) {
            add(i, arr[i]);
        }
    }

    void add(int ind, T val) {
        while (ind < n) {
            bit[ind] += val;
            ind |= (ind + 1);
        }
    }

    T get(int ind) { return sum(ind, ind); }

    void change(int ind, T val) { add(ind, val - get(ind)); }

    T sum(int r) {
        T ret = 0;
        while (r >= 0) {
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }

    T sum(int l, int r) {
        if (l <= 0) return sum(r);
        return sum(r) - sum(l - 1);
    }
};
