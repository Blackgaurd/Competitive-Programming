// CCC '09 S2 - Lights Going On and Off

#include<cstdio>
#include<set>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int r, l, lights[30];
char c;
set<int> combs;
int main(){
    su(r); su(l);
    l--;
    for (int i=0; i<r; i++){
        for (int j=1<<l; j>=1; j>>=1){
            sc(c);
            if (c == '1') lights[i] += j;
        }
    }
    for (int i=r-2, cur=0; i>=0; i--){
        cur ^= lights[i];
        combs.insert(lights[r-1] ^ cur);
    }
    combs.insert(lights[r-1]);
    printf("%ld\n", combs.size());

    return 0;
}