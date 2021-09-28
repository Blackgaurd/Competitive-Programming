// Bob's Khanpsack

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

const int MM = 1e5 + 3;
int n, q;
ll psa[MM];
priority_queue<int> pq;
int main() {
    su(n);
    su(q);
    for (int i = 0, v; i < n; i++) {
        si(v);
        if (v > 0) {
            pq.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (pq.empty())
            psa[i] = psa[i - 1];
        else {
            psa[i] = psa[i - 1] + pq.top();
            pq.pop();
        }
    }

    for (int i = 0, k; i < q; i++) {
        su(k);
        printf("%lld\n", psa[k]);
    }

    return 0;
}