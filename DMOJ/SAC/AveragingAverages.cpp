// SAC '21 P4 - Averaging Averages

#include<cstdio>
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, q, a, b, psa[(int)1e6+3];
int main(){
    su(n); su(q);
    for (int i=1; i<=n; i++){
        su(psa[i]);
        psa[i] += psa[i-1];
    }
    while (q--){
        su(a); su(b);
        printf("%d\n", (psa[b] - psa[a-1])/(b-a+1));
    }

    return 0;
}