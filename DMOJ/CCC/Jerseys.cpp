// CCC '15 S2 - Jerseys

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e6+3;
int j, a, ans = 0;
char arr[MM];
int main(){
    su(j); su(a);
    for (int i=1; i<=j; i++) sc(arr[i]);
    for (int i=1; i<=a; i++){
        char s; int n;
        sc(s); su(n);
        if (arr[n] <= s){
            ans++;
            arr[n] = 'Z';
        }
    }
    printf("%d\n", ans);

    return 0;
}

