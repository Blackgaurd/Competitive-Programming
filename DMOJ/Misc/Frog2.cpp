// Frog 2

#include<cstdio>
#include<algorithm>
#include<climits>
#include<string.h>
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

const int MM = 1e5+3;
int n, k, h[MM], dp[MM];
int main(){
    su(n); su(k);
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for (int i=1; i<=n; i++){
        su(h[i]);
        for (int j=1; j<=k && j<i; j++){
            dp[i] = std::min(dp[i], abs(h[i] - h[i-j]) + dp[i-j]);
        }
    }
    printf("%d\n", dp[n]);

    return 0;
}