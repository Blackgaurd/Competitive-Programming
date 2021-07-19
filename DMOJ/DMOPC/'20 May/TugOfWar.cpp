// DMOPC '20 Contest 6 P1 - Tug of War

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

const int MM = 1e6+3;
int n, arr[MM];
ll psa[MM];
ll get(int i, int spl, int l, int r){
    if (i == n) return psa[n];
    if (i == 1) return l;
    if (i >= spl) return psa[i+1] - r;
    else return psa[i-1] + l;
}
int main(){
    su(n);
    for (int i=1; i<=n; i++){
        su(arr[i]);
        psa[i] = psa[i-1] + arr[i];
    }
    for (int i=1; i<=n; i++){
        int r = arr[i], l = arr[i-1];
        int lo = 1, hi = n;
        ll ans = LLONG_MAX;
        while (lo <= hi){
            int mid = (lo + hi) / 2;
            ll left = get(mid, i, l, r);
            if (abs(psa[n] - left * 2) < ans){
                ans = abs(psa[n] - left * 2);
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        printf("lo: %d, hi: %d, ans: %lld\n", lo, hi, ans);
    }

    return 0;
}