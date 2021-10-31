// COCI '07 Contest 4 #5 Poklon

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

const int MM = 1e6 + 3;
int n, ans[MM];
pii arr[MM];
bool comp(const pii &a, const pii &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
bool fits(const pii &a, const pii &b) {
    return a.first <= b.first && a.second >= b.second;
}
int main() {
    su(n);
    for (int i = 0; i < n; i++) {
        su(arr[i].first);
        su(arr[i].second);
    }
    sort(arr, arr + n, comp);
    BIT<int> bit(MM);
    int mx = 0, last = -1;
    for (int i = 0; i < n; i++) {
        ans[i] = bit.query(arr[i].second) + 1;
        bit.update(arr[i].second, ans[i]);
        if (ans[i] > mx) {
            mx = ans[i];
            last = i;
        }
    }
    pii cur = arr[last];
    vector<int> inds = {last};
    for (int i = last - 1; i >= 0; i--) {
        if (ans[last] - 1 == ans[i] && fits(cur, arr[i])) {
            cur = arr[i];
            inds.push_back(i);
            last = i;
        }
    }
    printf("%ld\n", inds.size());
    for (int i : inds) {
        printf("%d %d\n", arr[i].first, arr[i].second);
    }

    return 0;
}