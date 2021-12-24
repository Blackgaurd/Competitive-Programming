// USACO 2018 Open Silver P1 - Out of Sorts

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
vector<pair<int, int>> arr;
int main() {  // maximum distance number is from sorted position + 1
    su(n);
    for (int i = 0; i < n; i++) {
        arr.emplace_back(0, i);
        su(arr[i].first);
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, arr[i].second - i);
    }
    printf("%d\n", ans + 1);
}