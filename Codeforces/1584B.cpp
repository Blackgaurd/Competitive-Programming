// B. Coloring Rectangles

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

int t, n, m;
int main() {
    #ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    su(t);
    while (t--) {
        su(n);
        su(m);
        printf("%d\n", (n * m) / 3 + !!(n * m % 3));
    }

    return 0;
}
