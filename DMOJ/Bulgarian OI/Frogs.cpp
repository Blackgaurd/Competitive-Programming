// Bulgarian OI '09 P4 - Frogs

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
int n, h[MM], j[MM];
deque<int> q = {INT_MAX};
int main(){
    su(n);
    for (int i=1; i<=n; i++)
        su(h[i]);
    for (int i=1; i<=n; i++)
        su(j[i]);
    for (int i=n; i>=1; i--){
        while (h[i] >= q.front())
            q.pop_front();
        j[i] = j[i] > q.size()-1 ? -1 : q[j[i]-1];
        q.push_front(h[i]);
    }
    for (int i=1; i<=n; i++)
        printf("%d ", j[i]);
    printf("\n");

    return 0;
}