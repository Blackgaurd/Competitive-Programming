// An Animal Contest 5 P3 - Ski Resort

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
#define all(vec) vec.begin(), vec.end()
// clang-format on
typedef pair<int, int> pii;

const int MM = 2e5 + 3;
int n, k;
vector<pii> adj[MM], intervals;
vector<int> skill;
void dfs(int cur) {
    if (adj[cur].empty()) return;

    auto [lo, hi] = intervals[cur];
    lo--;
    sort(all(adj[cur]));
    for (int i = 0; i < adj[cur].size() - 1; i++) {
        auto [w, nxt] = adj[cur][i];
        if (w < lo + 1 || w > hi || hi == -1) {
            intervals[nxt] = {-1, -1};
            continue;
        }
        auto [w2, nxt2] = adj[cur][i + 1];
        intervals[nxt].first = lo + 1;
        intervals[nxt].second = lo = (w + w2) / 2;
        dfs(nxt);
    }
    auto [w, lst] = adj[cur].back();
    if (w < lo + 1 || w > hi || hi == -1)
        intervals[lst] = {-1, -1};
    else
        intervals[lst] = {lo + 1, hi};
    dfs(lst);
}
int main() {
#ifdef PC
    freopen("SkiResort.in", "r", stdin);
    freopen("SkiResort.out", "w", stdout);
#endif
    su(n);
    su(k);
    intervals.assign(n + 1, {-1, -1});
    for (int i = 0, a, b, w; i < n - 1; i++) {
        su(a);
        su(b);
        su(w);
        adj[a].emplace_back(w, b);
    }
    intervals[1] = {1, 1e9};
    dfs(1);

    skill.resize(k);
    for (int &i : skill) su(i);
    sort(all(skill));

    for (int i = 1; i <= n; i++) {
        auto [lo, hi] = intervals[i];
        if (hi == -1) {
            printf("0");
        } else {
            int lo_ind = lower_bound(all(skill), lo) - skill.begin();
            int hi_ind = lower_bound(all(skill), hi) - skill.begin();
            if (hi_ind == k || skill[hi_ind] > hi) hi_ind--;
            printf("%d", max(0, hi_ind - lo_ind + 1));
        }
        if (i != n) printf(" ");
    }
    printf("\n");
}