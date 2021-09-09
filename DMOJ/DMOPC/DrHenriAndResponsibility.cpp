// DMOPC '18 Contest 4 P2 - Dr. Henri and Responsibility
// knapsack as close to half of total sum as possible

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 703;
int n, dp[MM], sum = 0, ans = 0;
int main(){
    su(n);
    for (int i=1; i<=n; i++){
        su(dp[i]);
        sum += dp[i];
    }
    sum /= 2;

    set<int> s = {0};
    int cur_sum = 0;
    for (int i=1; i<=n; i++){
        cur_sum += dp[i];
        auto it = s.lower_bound(cur_sum - sum);
        if (it != s.end()){
            ans = max(ans, cur_sum - *it);
        }
        s.insert(cur_sum);
    }
    printf("%d\n", abs(ans - sum));

    return 0;
}