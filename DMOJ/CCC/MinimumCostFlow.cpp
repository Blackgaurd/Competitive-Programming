// CCC '17 S4 - Minimum Cost Flow
// partials: d = 0

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

const int MM = 1e5 + 3;
int n, m, d, p[MM];
struct edge {
    int a, b, w, ind;
};
vector<edge> arr, original;
int flead(int x) {
    if (p[x] != x) p[x] = flead(p[x]);
    return p[x];
}
int main() {
    su(n);
    su(m);
    su(d);
    for (int i = 1; i <= n; i++) p[i] = i;

    arr.resize(m);
    original.resize(n);
    for (int i = 0; i < m; i++) {
        su(arr[i].a);
        su(arr[i].b);
        su(arr[i].w);
        arr[i].ind = i;
        if (i < n - 1) original[i] = arr[i];
    }
    sort(arr.begin(), arr.end(), [](edge &a, edge &b) { return a.w == b.w ? a.ind < b.ind : a.w < b.w; });

    int ans = 0;
    vector<bool> taken(n, false);
    for (auto [a, b, w, ind] : arr) {
        int pa = flead(a), pb = flead(b);
        if (pa != pb) {
            p[pa] = pb;
            if (ind < n - 1) {
                taken[ind] = true;
            } else {
                ans++;
            }
        }
    }
    for (auto [a, b, w, ind] : original) {
        if (taken[ind]) continue;
        cout << a << ' ' << b << '\n';
    }
    printf("%d\n", ans);
}