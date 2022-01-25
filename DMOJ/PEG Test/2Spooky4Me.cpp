// 2spooky4me
// coord compression + psa

#include <bits/stdc++.h>
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

int n, l, s, ans;
map<int, int> psa;
int main(){
    #ifdef PC
    freopen("2Spooky4Me.in", "r", stdin);
    freopen("2Spooky4Me.out", "w", stdout);
    #endif
    su(n); su(l); su(s);
    for (int i=0, a, b, c; i<n; i++){
        su(a); su(b); su(c);
        psa[a] += c;
        psa[b+1] -= c;
    }
    psa[l] = 0;
    psa[0] = 0;
    for (auto it = next(psa.begin()); it != prev(psa.end()); it++){
        it->second += prev(it)->second;
        if (it->second >= s){
            int span = next(it)->first - it->first;
            l -= span;
        }
    }
    printf("%d\n", l);
}