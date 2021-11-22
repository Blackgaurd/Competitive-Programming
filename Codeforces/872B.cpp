// B. Maximum of Maximums of Minimums
// doesn't work

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

const int MM = 1e5+3;
int n, k, arr[MM], pre[MM], mx = INT_MIN;
int main(){
    #ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    su(n); su(k);
    pre[0] = INT_MAX;
    for (int i=1; i<=n; i++){
        si(arr[i]);
        mx = max(mx, arr[i]);
        pre[i] = min(pre[i-1], arr[i]);
    }
    if (k == 1) printf("%d\n", pre[n]);
    else if (k == 2){
        int rmin = pre[n], ans = INT_MIN;
        pre[0] = INT_MIN;
        for (int i=n; i>=0; i--){
            ans = max(ans, max(pre[i], rmin));
            // cout << arr[i] << ' ' << pre[i] << ' ' << rmin << '\n';
            rmin = max(rmin, arr[i]);
        }
        printf("%d\n", ans);
    }
    else printf("%d\n", mx);


    return 0;
}
