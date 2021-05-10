// DMOPC '17 Contest 5 P5 - XOR Bridges

#include<bits/stdc++.h>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

const int MN = 2e5+3, MM = 1e9+3;
int n, m, q, arr[MN], p[MM], start = 0;
int flead(int __x){
    if (p[__x]!=__x) p[__x] = flead(p[__x]);
    return p[__x];
}
int main(){
    su(n); su(m); su(q);
    for (int i=1; i<=n; i++){
        su(arr[i]);
        start = max(start, int(log2(arr[i])));
        p[i] = i;
    }
    start = max(start, int(log2(m)));
    for (int bit=1<<start; bit>=1; bit >>= 1){
        if (m & bit){

        }
        else {
            
        }
    }

    return 0;
}