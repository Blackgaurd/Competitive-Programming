// CCC '13 S3 - Chances of Winning

#include<bits/stdc++.h>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int t, g, points[5], played[5], ans;
int main(){
    su(t); su(g);
    ans = pow(3, 6-g);
    for (int i=0; i<g; i++){
        int a, b, sa, sb;
        su(a); su(b); su(sa); su(sb);
        if (sa > sb) points[a] += 2;
        else if (sb > sa) points[b] += 2;
        else {
            points[a]++;
            points[b]++;
        }
        played[a]++;
        played[b]++;
    }

    return 0;
}