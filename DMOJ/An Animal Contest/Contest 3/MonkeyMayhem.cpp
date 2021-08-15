// An Animal Contest 3 P4 - Monkey Mayhem

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef long long ll;

int n, m;
ll ans = 0;
unordered_map<int, int> mp1, mp2;
int main(){
    su(n); su(m);
    for (int i=1; i<=n; i++){
        int a; si(a);
        if (a != -1) mp1[a-i]++;
    }
    for (int i=1; i<=m; i++){
        int a; si(a);
        if (a != -1) mp2[a-i]++;
    }
    for (auto p: mp1){
        ans += min(p.second, mp2[p.first]);
    }
    printf("%lld\n", ans);

    return 0;
}