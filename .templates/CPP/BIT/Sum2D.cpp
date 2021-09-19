// 2D Binary Indexed Tree

#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT2D{
    vector<vector<T>> bit;
    int n, m;

    BIT2D(int n, int m){
        this->n = n;
        this->m = m;
        bit.assign(n, vector<T>(m, 0));
    }

    BIT2D(vector<vector<T>> &arr) : BIT2D(arr.size(), arr[0].size()){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                add(i, j, arr[i][j]);
    }

    T sum(int x, int y) {
        T ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, T delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }

    T sum(int x1, int y1, int x2, int y2){
        x1--; y1--;
        return sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);
    }
};
