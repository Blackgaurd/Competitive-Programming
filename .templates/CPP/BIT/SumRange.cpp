// 1D Binary Indexed Tree
// with O(logn) range updates
// and O(logn) range queries
// space complexity O(2n)

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT {
    vector<T> b1, b2;
    int n;

    BIT(int n) {
        this->n = n;
        b1.assign(n, 0);
        b2.assign(n, 0);
    }

    // point query on vector 'bit'
    // use bit = b1 for arr[r]
    T query(vector<T> &bit, int ind) {
        T ret = 0;
        while (ind >= 0) {
            ret += bit[ind];
            ind = (ind & (ind + 1)) - 1;
        }
        return ret;
    }

    // range query [0..r]
    T query(int r) { return query(b1, r) * r - query(b2, r); }

    // range query [l..r]
    T query(int l, int r) { return query(r) - query(l - 1); }

    // point update
    void update(vector<T> &bit, int ind, T val) {
        while (ind < n) {
            bit[ind] += val;
            ind |= ind + 1;
        }
    }

    // friendly point update
    void update(int ind, int val){
        update(b1, ind, val);
    }

    // range update [l..r]
    void update(int l, int r, T val){
        update(b1, l, val);
        update(b1, r+1, -val);
        update(b2, l, val * (l - 1));
        update(b2, r + 1, -val * r);
    }
};

int main(){
    BIT<int> bit(10);
    bit.update(0, 5, 1);
    bit.update(bit.b1, 0, 100);
    cout << bit.query(2) << endl;
}