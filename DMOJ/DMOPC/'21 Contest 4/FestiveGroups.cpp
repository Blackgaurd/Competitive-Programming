// DMOPC '21 Contest 4 P2 - Festive Groups
// similar to sieve

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

const int MM = 5e6 + 3;
int n, ans;
vector<int> arr;
bool found[MM];
int main() {
    su(n);
    arr.resize(n);
    for (int i = 0; i < n; i++) 
        su(arr[i]);
    sort(arr.begin(), arr.end());
    for (int cur : arr) {
        if (found[cur]) continue;
        ans++;
        for (int i = cur; i < MM; i += cur)
            found[i] = true;
    }
    printf("%d\n", ans);
}