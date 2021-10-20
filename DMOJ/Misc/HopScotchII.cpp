// HopScotch II

#include<bits/stdc++.h>
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

const int MM = 1 << 23 + 3;
int n, k, par[MM];
ll arr[MM];
deque<ll> q;
int main(){
    su(n); su(k);
    for (int i=1; i<=n; i++){
        su(arr[i]);
        arr[i] += q.empty() ? 0 : arr[q.front()];
        par[i] = q.empty() ? 0 : q.front();
        while (!q.empty() && arr[i] < arr[q.back()]) q.pop_back();
        while (!q.empty() && i - q.front() + 1> k) q.pop_front();
        q.push_back(i);
    }
    for (int i=1; i<=n; i++) cout << par[i] << '\n';

    return 0;
}