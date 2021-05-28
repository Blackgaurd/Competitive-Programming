// UTS Open '21 P3 - Latin Class

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, h[30], tallest[30][30], ans = 0;
void solve(int start, int prev){
    if (start>n) {
        ans++;
        return;
    }
    for (int i=start; i<=n; i++){
        if (tallest[start][i]>=prev)
            solve(start+1, tallest[start][i]);
    }
}
int main(){
    sc(n);
    for (int i=1; i<=n; i++) cin >> h[i];
    for (int i=1; i<=n; i++){
        for (int j=i; j<=n; j++){
            tallest[i][j] = max(h[j], tallest[i][j-1]);
        }
    }
    solve(1, tallest[1][1]);
    cout << ans;

    return 0;
}