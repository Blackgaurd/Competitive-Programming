// ECOO '21 P3 - Quintessential Questions

#include<cstdio>
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

const int MM = 2e5+3;
int n, m, k, a, b, c, arr[MM][2];
int main(){
    su(n); su(m); su(k);
    while (k--){
        su(a); su(b); su(c);
        if (c > arr[b][0]){
            arr[b][0] = c;
            arr[b][1] = a;
        }
    }
    for (int i=1; i<=n; i++){
        if (arr[i][1]) printf("%d ", arr[i][1]);
        else printf("-1 ");
    }

    return 0;
}