// Another Contest 3 Problem 4 - Range Updates and Range Queries

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

template <typename T>
struct BIT {
    vector<T> b1, b2;
    int n;

    BIT(int n) {
        this->n = n;
        b1.assign(n, 0);
        b2.assign(n, 0);
    }

    T query(vector<T> &bit, int ind) {
        T ret = 0;
        while (ind >= 0) {
            ret += bit[ind];
            ind = (ind & (ind + 1)) - 1;
        }
        return ret;
    }

    T query(int r) { return query(b1, r) * r - query(b2, r); }

    T query(int l, int r) { return query(r) - query(l - 1); }

    void update(vector<T> &bit, int ind, T val) {
        while (ind < n) {
            bit[ind] += val;
            ind |= ind + 1;
        }
    }

    void update(int ind, int val){
        update(b1, ind, val);
    }

    void update(int l, int r, T val){
        update(b1, l, val);
        update(b1, r+1, -val);
        update(b2, l, val * (l - 1));
        update(b2, r + 1, -val * r);
    }
};

int n, q;
int main(){
    su(n); su(q);
    BIT<int> bit(n + 1);
    while (q--){
        char c; sc(c);
        if (c == '1'){
            int l, r, val;
            su(l); su(r); su(val);
            bit.update(l, r, val);
        }
        else {
            int l, r;
            su(l); su(r);
            printf("ans: %d\n", bit.query(l, r));
        }
    }

    return 0;
}