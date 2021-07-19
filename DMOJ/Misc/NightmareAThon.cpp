// Nightmare-a-thon

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 5e5+3;
int n, q, a, b, arr[MM], maxl[MM], maxr[MM], freql[MM], freqr[MM];
int main(){
    su(n); su(q);
    for (int i=1; i<=n; i++){
        su(arr[i]);
        maxl[i] = max(maxl[i-1], arr[i]);
        if (maxl[i] != maxl[i-1]) freql[i] = 1;
        else {
            freql[i] = freql[i-1];
            if (maxl[i] == arr[i]) freql[i]++;
        }
    }
    for (int i=n; i>=1; i--){
        maxr[i] = max(maxr[i+1], arr[i]);
        if (maxr[i] != maxr[i+1]) freqr[i] = 1;
        else {
            freqr[i] = freqr[i+1];
            if (maxr[i] == arr[i]) freqr[i]++;
        }
    }
    while (q--){
        su(a); su(b);
        printf("%d ", max(maxl[a-1], maxr[b+1]));
        if (maxl[a-1] == maxr[b+1]) printf("%d\n", freql[a-1] + freqr[b+1]);
        else if (maxl[a-1] > maxr[b+1]) printf("%d\n", freql[a-1]);
        else printf("%d\n", freqr[b+1]);
    }

    return 0;
}
