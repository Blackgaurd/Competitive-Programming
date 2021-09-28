// Bob's Contest Score

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

int n, arr[6];
unordered_set<int> cnt;
void solve(int ind, int sum) {
    if (ind > n) {
        cnt.insert(sum);
        return;
    }
    solve(ind + 1, sum);
    solve(ind + 1, sum + arr[ind]);
}
int main() {
    su(n);
    for (int i = 1; i <= n; i++) {
        su(arr[i]);
    }
    solve(1, 0);
    printf("%ld\n", cnt.size());

    return 0;
}