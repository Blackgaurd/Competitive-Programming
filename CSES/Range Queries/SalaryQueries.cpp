// Salary Queries

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
int n, q;
map<int, int> q_mp;
vector<int> initial, nums;
struct query {
    char c;
    int a, b;
};
vector<query> qs;
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    su(q);
    initial.resize(n);
    for (int i = 0; i < n; i++) {
        su(initial[i]);
        nums.push_back(initial[i]);
    }
    qs.resize(q);
    for (int i = 0; i < q; i++) {
        sc(qs[i].c);
        su(qs[i].a);
        su(qs[i].b);
        if (qs[i].c == '?') {
            nums.push_back(qs[i].a);
        }
        nums.push_back(qs[i].b);
    }
    sort(nums.begin(), nums.end());
    int ind = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 and nums[i] == nums[i - 1]) continue;
        q_mp[nums[i]] = ind++;
    }
    BIT<int> bit(ind + 1);
    for (int i : initial) {
        bit.update(q_mp[i], 1);
    }
    for (auto [c, a, b] : qs) {
        if (c == '!') {
            a--;
            int before = initial[a];
            initial[a] = b;
            bit.update(q_mp[before], -1);
            bit.update(q_mp[b], 1);
        } else {
            printf("%d\n", bit.query(q_mp[a], q_mp[b]));
        }
    }

    return 0;
}