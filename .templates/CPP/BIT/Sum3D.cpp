// 3D Binary Indexed Tree

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT3D {
#define vec vector

    vec<vec<vec<T>>> bit;
    int x, y, z;

    BIT3D(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
        bit = vec<vec<vec<T>>>(x, vec<vec<T>>(y, vec<T>(z, 0)));
    }

    BIT3D(vec<vec<vec<T>>> &arr)
        : BIT3D(arr.size(), arr[0].size(), arr[0][0].size()) {
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                for (int k = 0; k < z; k++) add(i, j, k, arr[i][j][k]);
    }

    void add(int x, int y, int z, int val) {
        for (int i = x; i < this->x; i = i | (i + 1))
            for (int j = y; j < this->y; j = j | (j + 1))
                for (int k = z; k < this->z; k = k | (k + 1))
                    bit[i][j][k] += val;
    }

    T sum(int x, int y, int z) {
        T ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                for (int k = z; k >= 0; k = (k & (k + 1)) - 1)
                    ret += bit[i][j][k];
        return ret;
    }

    T sum(int x1, int y1, int z1, int x2, int y2, int z2) {
        x1--;
        y1--;
        z1--;
        T ttl = sum(x2, y2, z2);
        T f1 = sum(x1, y2, z2), f2 = sum(x2, y1, z2), f3 = sum(x2, y2, z1);
        T e1 = sum(x2, y1, z1), e2 = sum(x1, y2, z1), e3 = sum(x1, y1, z2);
        T sm = sum(x1, y1, z1);
        return ttl - f1 - f2 - f3 + e1 + e2 + e3 - sm;
    }

    T get(int x, int y, int z) { return sum(x, y, z, x, y, z); }
};