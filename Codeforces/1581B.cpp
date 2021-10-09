// B. Diameter of Graph

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
typedef long long ll;

ll t, m, n, k;
int main(){
    su(t);
    while (t--){
        su(n); su(m); su(k);
        k -= 2;
        if (n == 1){
            // do something
        }
        int min_dia = (m * (m - 1) / 2 >= n) ? 1 : 2;
        printf("%s\n", min_dia <= k ? "YES" : "NO");
    }

    return 0;
}