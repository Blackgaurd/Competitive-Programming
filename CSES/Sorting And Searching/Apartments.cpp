// Apartments

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

int n, m, k, ans;
vector<int> a, b;
bool small(int x, int y) {
    return y < x - k;
}
bool big(int x, int y) {
    return y > x + k;
}
bool in_range(int x, int y) {
    return !small(x, y) && !big(x, y);
}
int main() {
    su(n);
    su(m);
    su(k);
    a.resize(n);
    b.resize(m);
    for (int &i : a) su(i);
    for (int &i : b) su(i);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int pa = 0, pb = 0;
    while (pa < n || pb < m) {
        if (in_range(a[pa], b[pb])) {
            ans++;
            if (pa < n) pa++;
            if (pb < m) pb++;
            if (pa == n && pb == m) break;
        } else if (small(a[pa], b[pb])) {
            if (pb < m - 1)
                pb++;
            else
                break;
        } else {
            if (pa < n - 1)
                pa++;
            else
                break;
        }
    }
    printf("%d\n", ans);

    return 0;
}