// UTS Open '21 P6 - Terra Mater

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int t, n, k;
int main(){
    sc(t);
    while (t--){
        int ans = 0;
        sc(n); sc(k);
        int prev; sc(prev);
        for (int i=1; i<n; i++){
            int a; sc(a);
            ans = max(ans, abs(a-prev));
            prev = a;
        }
        cout << ans << '\n';
    }
}