// DMOPC '15 Contest 2 P4 - Personal Assistant

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

struct trp{
    ll s, f, w;
    trp(ll a, ll b, ll c){
        s = a;
        f = a + b;
        w = c;
    }
    bool operator < (const trp& other) const {return f < other.f;}
};
int n;
ll dp[(int)1e5+3];
vector<trp> arr;
int binlower(int hi, ll x){
    int lo = 0, ind = -1;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (arr[mid].f > x) hi = mid - 1;
        else {
            ind = mid;
            lo = mid + 1;
        }
    }
    return ind;
}
int main(){
    su(n);
    arr.emplace_back(0, 0, 0);
    for (ll i=0, a, b, w; i<n; i++){
        su(a); su(b); su(w);
        arr.emplace_back(a, b, w);
    }
    sort(arr.begin(), arr.end());
    for (int i=1; i<=n; i++){
        int ind = binlower(i, arr[i].s);
        dp[i] = max(dp[i-1], dp[ind] + arr[i].w);
    }
    printf("%lld\n", dp[n]);

    return 0;
}