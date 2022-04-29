// Collecting Numbers

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

int n;
vector<int> arr, pos;
int main() {
    su(n);
    arr.resize(n + 1);
    pos.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        su(arr[i]);
        pos[arr[i]] = i;
    }
    int ans = 1, l = 1;
    for (int i = 1; i <= n; i++) {
        if (pos[i] < l) ans += 1;
        l = pos[i];
    }
    printf("%d\n", ans);
}