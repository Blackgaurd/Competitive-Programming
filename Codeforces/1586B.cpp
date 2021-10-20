// B. Omkar and Heavenly Tree

#include<bits/stdc++.h>
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

int t, n, m;
int main(){
    su(t);
    while (t--){
        unordered_set<int> seen;
        su(n); su(m);
        for (int i=1; i<=n; i++) seen.insert(i);
        for (int i=1, a, b, c; i<=m; i++){
            su(a); su(b); su(c);
            if (seen.find(b) != seen.end()) seen.erase(b);
        }
        int mid = *seen.begin();
        for (int i=1; i<=n; i++){
            if (i != mid) printf("%d %d\n", mid, i);
        }
    }

    return 0;
}