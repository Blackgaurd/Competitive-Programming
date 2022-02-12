// MNYC '16: Rocks

#include <bits/stdc++.h>
using namespace std;

const int MM = 1e4 + 3;
template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int size) {
        n = size;
        bit.assign(n, 0);
    }
    void update(int ind, T val) {
        while (ind < n) {
            bit[ind] += val;
            ind |= (ind + 1);
        }
    }
    T query(int r) {
        T ret = 0;
        while (r >= 0) {
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }
    T query(int l, int r) {
        if (l <= 0) return query(r);
        return query(r) - query(l - 1);
    }
};
int c, ptr;
unordered_map<string, int> pos, mass;
BIT<int> bit(MM);
int calc(string &name) {
    int ret = 0;
    for (char c : name) {
        ret += c - 'a' + 1;
    }
    return ret;
}
void add_rock() {
    string name;
    cin >> name;
    if (pos.find(name) != pos.end()) {
        printf("Can't add %s\n", name.c_str());
        return;
    }
    pos[name] = ++ptr;
    mass[name] = calc(name);
    bit.update(ptr, mass[name]);
}
void swap_rocks() {
    string a, b;
    cin >> a >> b;
    bit.update(pos[a], mass[b] - mass[a]);
    bit.update(pos[b], mass[a] - mass[b]);
    swap(pos[a], pos[b]);
}
void output_mass() {
    string x, y;
    cin >> x >> y;
    int posx = pos[x], posy = pos[y];
    if (posx > posy) swap(posx, posy);
    printf("%d\n", bit.query(posx, posy));
}
void replace_rock() {
    string x, y;
    cin >> x >> y;
    pos[y] = pos[x];
    mass[y] = calc(y);
    bit.update(pos[x], mass[y] - mass[x]);
    pos.erase(x);
}
void output_size() {
    printf("%d\n", ptr);
}
int main() {
    #ifdef PC
    freopen("Rocks.in", "r", stdin);
    freopen("Rocks.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> c;
    while (c--) {
        char com;
        cin >> com;
        switch (com) {
            case 'A':
                add_rock();
                break;
            case 'S':
                swap_rocks();
                break;
            case 'M':
                output_mass();
                break;
            case 'R':
                replace_rock();
                break;
            case 'N':
                output_size();
                break;
        }
    }
}
