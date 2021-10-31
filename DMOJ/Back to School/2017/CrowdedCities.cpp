// Back From querymer '17 P6: Crowded Cities
// 3d longest increase (decreasing) subsequence

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
typedef long long ll;
typedef pair<long long, int> pii;

template <typename T>
struct BIT2D {
    unordered_map<int, unordered_map<int, pair<T, int>>> bit;
    int n, m;
    BIT2D(int n, int m) {
        this->n = n;
        this->m = m;
    }
    pair<T, int> query(int x, int y) {
        T ret = 0;
        int ind = -1;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                if (ret < bit[i][j].first) {
                    ret = bit[i][j].first;
                    ind = bit[i][j].second;
                }
            }
        }
        return {ret, ind};
    }
    void update(int x, int y, T val, int ind) {
        for (int i = x; i < n; i = i | (i + 1)) {
            for (int j = y; j < m; j = j | (j + 1)) {
                if (bit[i][j].first < val) {
                    bit[i][j].first = val;
                    bit[i][j].second = ind;
                }
            }
        }
    }
};

const int MM = 1e5 + 3, MS = 5003;
int n, par[MM], last = 0;
ll ans, mx = 0;
struct block {
    int h, l, w, p, ind;
    bool operator<(const block &other) {
        if (h != other.h) return h < other.h;
        return w < other.w && l < other.l;
    }
} arr[MM];
int main() {
    // read input
    su(n);
    for (int i = 1; i <= n; i++) {
        su(arr[i].h);
        su(arr[i].w);
        su(arr[i].l);
        su(arr[i].p);
        arr[i].ind = i;
        if (arr[i].w > arr[i].l) swap(arr[i].w, arr[i].l);
    }
    // sort by height to turn into 2d
    sort(arr + 1, arr + n + 1);
    // 2d lis
    BIT2D<ll> bit(MS, MS);
    for (int i = 1; i <= n; i++) {
        pii ret = bit.query(arr[i].w, arr[i].l);
        ans = ret.first + arr[i].p;
        bit.update(arr[i].w, arr[i].l, ans, i);
        par[i] = ret.second;
        if (ans > mx){
            mx = ans;
            last = i;
        }
    }
    printf("%lld\n", mx);
    vector<int> inds;
    for (; last != -1; last = par[last]){
        inds.push_back(last);
    }
    printf("%ld\n", inds.size());
    for (int i: inds){
        printf("%d ", arr[i].ind);
    }
    printf("\n");

    return 0;
}