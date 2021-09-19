// COCI '08 Contest 2 #3 Perket

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int n, arr[10][2];
long long solve(int ind, long long sour, long long bitter, int cnt){
    if (ind >= n){
        if (cnt == 0) return LLONG_MAX;
        return abs(sour - bitter);
    }
    long long ans = LLONG_MAX;
    ans = min(ans, solve(ind + 1, sour, bitter, cnt));
    ans = min(ans, solve(ind + 1, sour * arr[ind][0], bitter + arr[ind][1], cnt + 1));
    return ans;
}
int main(){
    su(n);
    for (int i=0; i<n; i++){
        su(arr[i][0]);
        su(arr[i][1]);
    }
    printf("%lld\n", solve(0, 1, 0, 0));

    return 0;
}