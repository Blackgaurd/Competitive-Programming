// VM7WC '15 #2 Gold - Uniting the Earth Empire

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef pair<long long, int> pll;

int n;
long long a, ans = 0;
vector<pll> q = {{LLONG_MAX, 0}};
int main(){
    su(n);
    while (n--){
        su(a);
        int cnt = 1;
        while (a >= q.back().first){
            ans += q.back().second;
            if (a == q.back().first) cnt += q.back().second;
            q.pop_back();
        }
        ans += q.back().first != LLONG_MAX;
        q.push_back({a, cnt});
    }
    printf("%lld\n", ans);

    return 0;
}