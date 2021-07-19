// Connected Components

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int n, p[1003];
int flead(int __x){
    if (p[__x]!=__x) p[__x] = flead(p[__x]);
    return p[__x];
}
int main(){
    su(n);
    for (int i=1; i<=n; i++) p[i] = i;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            int a; su(a);
            if (a == 1)
                if (flead(i) != flead(j))
                    p[flead(i)] = flead(j);
        }
    }
    for (int i=1; i<=n; i++) flead(i);
    for (int i=1; i<=n; i++){
        if (!p[i]) continue;
        printf("%d ", i);
        for (int j=i+1; j<=n; j++){
            if (p[j] == p[i]){
                printf("%d ", j);
                p[j] = 0;
            }
        }
        p[i] = 0;
        printf("\n");
    }

    return 0;
}