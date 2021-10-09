// COCI '10 Contest 7 #3 Gitara

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

const int TONE = 6;
int n, p, ans = 0;
priority_queue<int, vector<int>> _pq[TONE];
int main() {
    su(n);
    su(p);
    while (n--) {
        int t, f;
        su(t);
        su(f);
        priority_queue<int> &pq = _pq[t-1];
        if (pq.empty() || f > pq.top()) {
            pq.push(f);
            ans++;
        }
        else {
            while (!pq.empty() && f < pq.top()){
                pq.pop();
                ans++;
            }
            if (pq.empty() || f != pq.top()){
                pq.push(f);
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}