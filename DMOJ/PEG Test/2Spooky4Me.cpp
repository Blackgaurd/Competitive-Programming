// 2spooky4me

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

const int MM = 1e4+3;
int n, l, s, psa[MM];
map<int, int> mp;
struct trp{
    int a, b, s;
} arr[MM];
int main(){
    su(n); su(l); su(s);
    for (int i=0; i<n; i++){
        su(arr[i].a);
        su(arr[i].b);
        su(arr[i].s);
        mp[arr[i].a] = 0;
        mp[arr[i].b] = 0;
    }
    for (auto &p: mp){
        
    }

    return 0;
}