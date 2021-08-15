// DMPG '16 S5 - Pizza Bag

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef long long ll;

const int MM = 1e5+3;
int n, k;
ll psa[MM*2], ans = 0;
deque<int> q = {0};
int main(){
    su(n); su(k);
    for (int i=1; i<=n; i++){
        si(psa[i]);
        psa[i+n] = psa[i];
    }
    for (int i=1; i<=2*n; i++){
        psa[i] += psa[i-1];
        while (!q.empty() && psa[q.back()] > psa[i])
            q.pop_back();
        q.push_back(i);
        while (!q.empty() && q.front() < i-k)
            q.pop_front();
        ans = max(ans, psa[i] - psa[q.back()-1]);
    }
    printf("%lld\n", ans);

    return 0;
}