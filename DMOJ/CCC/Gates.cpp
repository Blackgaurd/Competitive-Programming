// CCC '15 S3 - Gates

#include <bits/stdc++.h>
using namespace std;

#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

// 1 = open, 0 = taken
int g, p, ans = 0;
bitset<(int)1e5+3> gates;
int main(){
    gates.flip();
    su(g); su(p);
    for (int i=0; i<p; i++){
        int a; su(a);
        int ind = gates._Find_next(g-a-1);
        if (ind == g){
            printf("ans: %d\n", i);
            return 0;
        }
        gates[ind] = 0;
    }
    printf("ans: %d\n", p);
    return 0;
}