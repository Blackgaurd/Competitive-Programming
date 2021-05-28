// UCC Coding Competition '20 P3 - Farmer Bob

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int h, t, m, mx = -1;
vector<int> trac;
int main(){
    su(h); su(t);
    for (int i=0; i<t; i++){
        int a; su(a);
        trac.push_back(a);
    }
    sort(trac.begin(), trac.end());
    su(m);
    int prev = 0;
    for (int i=0; i<m; i++){
        char c; sc(c);
        if (c == '1') {
            mx = max(mx, i-prev);
            prev = i;
        }
    }
    mx = max(mx, m-1-prev);
    for (int i=t-1; i>=0; i--){
        if (trac[i] <= mx-1){
            printf("%d\n", (h-1)/trac[i]+1);
            return 0;
        }
    }

    return 0;
}