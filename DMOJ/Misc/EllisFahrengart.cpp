// Ellis Fahrengart
// inversion (BIT) + offline queries + coord compression
// sort pairs [p, q] by q

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
typedef pair<int, int> pii;

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
            bit[ind] = max(bit[ind], val);
            ind |= (ind + 1);
        }
    }
    T query(int r) {
        T ret = 0;
        while (r >= 0) {
            ret = max(ret, bit[r]);
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }
};
struct trp {
    int first, second, ind;
};

const int MM = 1e5 + 3;
int n, q;
vector<int> arr;
vector<trp> queries;
map<int, int> mp;
int main() {
    #ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    su(n);
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        su(arr[i]);
        mp[arr[i]] = 0;
    }
    int ind = 0;
    for (auto [a, _] : mp) {
        mp[a] = ++ind;
    }
    su(q);
    queries.resize(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        su(queries[i].first);
        su(queries[i].second);
        queries[i].ind = i;
    }
    sort(queries.begin(), queries.end(), [](trp &a, trp &b) { return a.first < b.first; });
    for (auto [a, b, c] : queries){
        printf("%d %d %d\n", a, b, c);
    }

    return 0;
}