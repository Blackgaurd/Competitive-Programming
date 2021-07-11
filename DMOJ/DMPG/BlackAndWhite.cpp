// DMPG '15 S5 - Black and White

#include<bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 1e4+3;
int n, m, x, y, w, h, ans = 0;
short arr[MM][MM];
int main(){
    su(n); su(m);
    while (m--){
        su(x); su(y); su(w); su(h);
        x++; y++;
        arr[x][y]++;
        arr[x+w][y]--;
        arr[x][y+h]--;
        arr[x+w][y+h]++;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            arr[i][j] %= 2;
            ans += abs(arr[i][j]);
        }
    }
    printf("%d\n", ans);

    return 0;
}