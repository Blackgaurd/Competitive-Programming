// DMOPC '21 Contest 8 P1 - Peanut Planning

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
#define watch(x) cout << (#x) << ": " << x << '\n'

int n, m;
multiset<int> s;
vector<int> ans;
int main() {
    su(n);
    su(m);
    for (int i = 0, a; i < n; i++) {
        su(a);
        s.insert(a);
    }
    for (int i = 1, cur = m; i < n; i++) {
        int needed = m - cur;
        auto it = s.find(needed);
        if (it == s.end()) {
            it = s.upper_bound(needed);
            if (it == s.end()) {
                printf("-1\n");
                return 0;
            }
        }
        ans.push_back(cur = *it);
        s.erase(it);
    }
    if (ans.back() + *s.begin() < m) {
        printf("-1\n");
        return 0;
    }
    ans.push_back(*s.begin());
    for (int i : ans) {
        printf("%d ", i);
    }
}