// DMOPC '21 Contest 2 P1 - Bosses

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

const int MM = 1e6 + 3;
int n, h, p, arr[MM], power[MM], ans = 0, mx = 0;
int main() {
    su(n);
    su(h);
    su(p);
    for (int i = 1; i <= n; i++) {
        su(arr[i]);
        mx = max(mx, arr[i]);
    }
    if (h <= p) {
        printf("%d\n", mx * h);
        return 0;
    }
    for (int i=1; i<n; i++){
        int use_h = h * max(arr[i] - power[i-1], 0) + p * max(arr[i+1] - arr[i], 0);
        int use_p = p * max(arr[i] - power[i-1], 0) + p * max(arr[i+1] - power[i-1], 0);
        if (use_h <= use_p){
            power[i] = max(power[i - 1], arr[i]);
            ans += h * max(arr[i] - power[i-1], 0);
        }
        else {
            power[i] = power[i-1];
            ans += p * max(arr[i] - power[i-1], 0);
        }
        //cout << ans << '\n';
    }
    ans += min(p * max(arr[n] - power[n-1], 0), h * max(arr[n] - power[n-1], 0));
    cout << ans << '\n';
}