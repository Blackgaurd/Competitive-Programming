// DMOPC '14 Contest 2 P4 - Deforestation

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, q, arr[1000005], psa[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    scan(n);
    for (int i=1; i<=n; i++) scan(arr[i]);
    for (int i=1; i<=n; i++) psa[i] = psa[i-1]+arr[i];
    scan(q);
    for (int i=0; i<q; i++){
        int a, b; scan(a); scan(b);
        cout << psa[b+1]-psa[a] << nl;
    }

    return 0;
}