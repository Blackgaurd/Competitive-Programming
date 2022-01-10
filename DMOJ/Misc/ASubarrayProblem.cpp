// A SubarrayProblem

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

int n;
int main() {
#ifdef PC
    freopen("ASubarrayProblem.in", "r", stdin);
    freopen("ASubarrayProblem.out", "w", stdout);
#endif
    su(n);
    vector<int> arr(n), ind(n);
    for (int i = 0; i < n; i++) {
        su(arr[i]);
        ind[arr[i]] = i;
    }
    int l = INT_MAX, r = INT_MIN, ans = 0;
    for (int i = 1; i <= n; i++) {
        l = min(l, ind[i]);
        r = max(r, ind[i]);
        if (r - l + 1 == i) {
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}