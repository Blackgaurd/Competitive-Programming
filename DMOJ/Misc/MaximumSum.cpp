// Maximum Sum

#include<cstdio>
#include<algorithm>
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, dp[100003];
int main(){
    su(n);
    for (int i=3, a; i<=n+2; i++){
        su(a);
        dp[i] = std::max(dp[i-2], dp[i-3]) + a;
    }
    printf("%d\n", std::max(dp[n+2], dp[n+1]));
    return 0;
}