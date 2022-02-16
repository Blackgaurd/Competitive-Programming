#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int size){
        p.resize(size + 1, -1);
    }
    int flead(int x){
        return p[x] < 0 ? x : p[x] = flead(p[x]);
    }
    bool same(int x, int y){
        return flead(x) == flead(y);
    }
    void unite(int x, int y){
        if (same(x, y)) return;
        int px = flead(x), py = flead(y);
        if (p[px] > p[py]) swap(px, py);
        p[px] += p[py];
        p[py] = px;
    }
};