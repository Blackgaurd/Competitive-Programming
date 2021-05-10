// COCI '10 Contest 3 #5 Diferencija

#include<cstdio>
#include<algorithm>

#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 3e5+3;
int n, arr[MM];
long long ans = 0;
int main(){
    su(n);
    for (int i=1; i<=n; i++) su(arr[i]);
    for (int i=1; i<=n; i++){
        int mx = arr[i], mn = arr[i];
        for (int j=i+1; j<=n; j++){
            mx = std::max(mx, arr[j]);
            mn = std::min(mn, arr[j]);
            ans += (mx - mn);
        }
    }
    printf("%lld\n", ans);

    return 0;
}