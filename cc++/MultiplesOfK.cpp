// Multiple of K

#include<bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define f first
#define s second

const int MM = 1e6+5;
int n, k, pre[MM], ans = -1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scan(n); scan(k);
    for (int i=1; i<=n; i++){
        int a; scan(a);
        pre[i] = (pre[i-1]+a)%k;
    }
    for (int i=n; i>=1; i--){
        for (int j=1; i<=i-1; j++){
            if (pre[i]==pre[j]) ans = max(ans, i-j);
        }
    }
    
    cout << ans << '\n';

    return 0;
}
// i cant sleep until i finish oh my