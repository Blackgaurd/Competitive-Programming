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
vector<edge> arr;
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
    for (int i = 0; i < m; i++) {
        su(arr[i].a);
        su(arr[i].b);
        su(arr[i].w);
        arr[i].ind = i;
    }
    sort(arr.begin(), arr.end(), [](edge &a, edge &b) { return a.w == b.w ? a.ind < b.ind : a.w < b.w; });

    // pos = last edge that was merged, largest weight bc vector is sorted
    int ans = 0, pos = 0, i = 0;
    for (auto [a, b, w, ind] : arr) {
        int pa = flead(a), pb = flead(b);
        if (pa != pb) {
            p[pa] = pb;
            ans += (ind >= n - 1);
            pos = i;
        }
        i++;
    }

    // largest weight not in original
    if (arr[pos].ind >= n - 1) {
        int largest = arr[pos].w;
        // reset dsu
        for (int i = 1; i <= n; i++) p[i] = i;
        for (auto [a, b, w, ind] : arr) {
            int pa = flead(a), pb = flead(b);
            if (pa != pb) {
                if (w < largest)
                    p[pa] = pb;
                else if (w == largest && ind < n - 1)
                    p[pa] = pb;
                else if (w <= d && ind < n - 1) {
                    ans--;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
}