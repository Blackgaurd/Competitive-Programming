// SAC '21 P5 - Friends of Friends

#include<cstdio>
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e5+3;
int n, q, p[MM], cnt[MM];
int flead(int __x){
    if (p[__x]!=__x) p[__x] = flead(p[__x]);
    return p[__x];
}
int main(){
    su(n); su(q);
    for (int i=1; i<=n; i++){
        p[i] = i;
        cnt[i] = 1;
    }
    while (q--){
        char c; sc(c);
        if (c == '1'){
            int a, b; su(a); su(b);
            if (flead(a) != flead(b)){
                cnt[flead(a)] += cnt[flead(b)];
                p[flead(b)] = flead(a);
            }
        }
        else {
            int a; su(a);
            printf("%d\n", cnt[flead(a)]);
        }
    }
    return 0;
}