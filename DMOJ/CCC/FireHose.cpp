// CCC '10 S3 - Firehose

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

const int MM = 1e6;
int h, houses[MM], k;

int check(int x) {
    int sol = h;
    for (int start = 0; houses[start] <= houses[0] + x * 2 && start < h;
         start++) {
        int cnt = 1;
        for (int nxt = start + 1, last = houses[start];
             nxt < h && houses[nxt] + x * 2 - MM < houses[start]; nxt++) {
            if (houses[nxt] > last) {
                last = houses[nxt] + x * 2;
                cnt++;
            }
        }
        sol = min(sol, cnt);
    }
    return sol;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    su(h);
    for (int i = 0; i < h; i++) su(houses[i]);
    sort(houses, houses + h);
    su(k);
    int lo = 0, hi = MM, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid) <= k) {
            hi = mid - 1;
            ans = mid;
        } else
            lo = mid + 1;
    }
    cout << ans << nl;

    return 0;
}