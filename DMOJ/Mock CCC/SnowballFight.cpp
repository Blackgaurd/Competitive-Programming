// Mock CCC '22 Contest 1 J4 - Snowball Fight

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
typedef pair<int, int> pii;

int n, t;
vector<deque<pii>> arr;
vector<int> ans;
int main() {
    su(n);
    su(t);
    arr.resize(n + 1);
    ans.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        su(ans[i]);
        arr[i].push_back({ans[i], 0});
    }
    for (int round = 1; round <= t; round++) {
        for (int i = 1; i <= n; i++) {
            if (arr[i].empty()) continue;
            auto [target, r] = arr[i].front();
            if (r == round) continue;
            arr[i].pop_front();

            ans[i] = target;
            arr[target].push_back({i, round});
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d", ans[i]);
        if (i != n) printf(" ");
    }
    printf("\n");
}