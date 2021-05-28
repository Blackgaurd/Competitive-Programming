// Summing A Sequence
// can take no numbers

#include<cstdio>
#include<algorithm>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
char _; bool _sign;

int n;
long long dp[(int)1e6+5];
int main(){
    su(n);
    for (int i=3; i<=n+2; i++){
        long long cur; si(cur);
        dp[i] = max({cur, dp[i-2]+cur, dp[i-3]+cur, dp[i-1], dp[i-2], dp[i-3]});
    }
    printf("%lld\n", dp[n+2]);
}