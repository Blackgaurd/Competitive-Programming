// Bob's Hated Number List

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int x, n, l, r, a;
set<int> nums;
int main(){
    su(x); su(n);
    l = r = x;
    while (n--){
        su(a);
        nums.insert(a);
        while (nums.count(l)) l--;
        while (nums.count(r)) r++;
    }
    if (abs(x-l) <= abs(x-r)) printf("%d\n", l);
    else printf("%d\n", r);

    return 0;
}