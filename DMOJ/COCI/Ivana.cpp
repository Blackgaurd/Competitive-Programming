// COCI '06 Contest 5 #5 Ivana

#include<cstdio>
#include<algorithm>
using namespace std;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
char _; bool _sign;

short n, dp[203][203], ans = 0;
int main(){
    su(n);
    for (int i=1; i<=n; i++){
        su(dp[i][i]);
        dp[i+n][i+n] = (dp[i][i]&=1);
    }
    for (int len=1; len<=n; len++){
        for (int l=1; l+len<=2*n; l++){
            int r = l + len;
            dp[l][r] = max(dp[l][l] - dp[l+1][r], dp[r][r] - dp[l][r-1]);
        }
    }
    for (int i=1; i<=n; i++){
        if (dp[i][i] - dp[i+1][i-1+n] > 0) ans++;
    }
    printf("%d\n", ans);

    return 0;
}