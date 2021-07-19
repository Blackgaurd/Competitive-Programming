// CCC '09 S5 - Wireless

#include<bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;

int n, m, k, x, y, r, b;
int arr[30003][1003];
int main(){
    su(n); su(m); su(k);
    while (k--){
        su(x); su(y); su(r); su(b);
        for (int i=max(1, y-r); i<=min(m, y+r); i++){
            int t = i - y;
            int j = sqrt(r*r - t*t);
            arr[i][max(1, x-j)] += b;
            arr[i][min(n, x+j)+1] -= b;
        }
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=m+1; j++){
            arr[i][j] += arr[i][j-1];
        }
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=m; j++) cout << arr[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
