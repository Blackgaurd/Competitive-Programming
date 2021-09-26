// Checkerboard Summation (Easy)

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

const int MM = 3003;
int n, m, psa[MM][MM];
bool black(int a, int b){
    return !((a + b) & 1);
}
int main(){
    su(m); su(n);
    while (true){
        int r, c, x;
        su(r); su(c); si(x);
        if (r == 0 && c == 0 && x == 0)
            break;
        psa[r][c] = (black(r, c) ? x : -x);
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            psa[i][j] += psa[i-1][j] + psa[i][j-1];
            psa[i][j] -= psa[i-1][j-1];
        }
    }
    while (true){
        int r1, c1, r2, c2, ans;
        su(r1); su(c1); su(r2); su(c2);
        if (r1 + c1 + r2 + c2 == 0)
            break;
        r1--; c1--;
        ans = psa[r2][c2] - psa[r2][c1] - psa[r1][c2] + psa[r1][c1];
        printf("%d\n", (black(r1, c1) ? ans : -ans));
    }

    return 0;
}