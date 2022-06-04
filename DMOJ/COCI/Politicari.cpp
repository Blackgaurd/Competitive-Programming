// COCI '19 Contest 5 #2 Političari

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
typedef long long ll;

const int MM = 503;
int n, arr[MM][MM], dis[MM][MM];
ll k;
int main() {
    su(n);
    su(k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            su(arr[i][j]);
        }
    }
    memset(dis, -1, sizeof(dis));

    int on_show = 1, accuse = 2;
    vector<int> p;
    for (ll i = 0; i < k; i++) {
        if (dis[accuse][on_show] != -1) {
            int prev_dis = dis[accuse][on_show];
            int len = i - prev_dis;
            cout << p[(k - 1 - prev_dis) % len + prev_dis] << '\n';
            return 0;
        }

        p.push_back(on_show);
        dis[accuse][on_show] = i;

        int nxt = arr[accuse][on_show];
        on_show = accuse;
        accuse = nxt;
    }
    cout << p[k - 1] << '\n';
}