// Bob's Particle

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
int n;
vector<pii> white, black;
int main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    su(n);
    white.resize(n);
    black.resize(n);
    for (int i = 0; i < n; i++) {
        su(white[i].first);
        su(white[i].second);
    }
    for (int i = 0; i < n; i++) {
        su(black[i].first);
        su(black[i].second);
    }
    sort(white.begin(), white.end());
    sort(black.begin(), black.end());
    BIT<int> bit(2 * n + 3);
    int ind = -1, ans = 0;
    vector<int> take;
    for (auto [x, y] : black) {
        while (ind < int(white.size()) - 1 && x >= white[ind + 1].first) {
            ind++;
            bit.update(white[ind].second, 1);
            take.push_back(white[ind].second);
        }
        if (bit.query(y) > 0) {
            // printf("less than %d: %d\n", y, bit.query(y));
            bit.update(take.back(), -1);
            take.pop_back();
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}