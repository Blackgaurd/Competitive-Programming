// ICPC PACNW 2016 H - Paint

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MM = 2e5+3;
int n;
ll k, dp[MM];
vector<pll> arr;
bool comp(pll a, pll b){
    return a.second < b.second;
}
int binlower(int hi, ll x){
    int lo = 0, ind = -1;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (arr[mid].second >= x) hi = mid - 1;
        else {
            ind = mid;
            lo = mid + 1;
        }
    }
    return ind;
}
int main(){
    su(n); su(k);
    for (int i=0; i<k; i++){
        ll a, b; su(a); su(b);
        arr.emplace_back(a, b);
    }
    sort(arr.begin(), arr.end(), comp);
    for (int i=0; i<k; i++){
        int ind = binlower(i-1, arr[i].first);
        if (ind == -1){
            dp[i] = arr[i].second - arr[i].first + 1;
        }
        else {
            dp[i] = max(dp[i-1], dp[ind] + arr[i].second - arr[i].first + 1);
        }
        //cout << dp[i] << '\n';
    }
    printf("%lld\n", n - dp[k-1]);

    return 0;
}