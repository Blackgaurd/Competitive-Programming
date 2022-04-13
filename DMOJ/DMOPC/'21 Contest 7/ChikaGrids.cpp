// DMOPC '21 Contest 7 P1 - Chika Grids

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

int n, m;
vector<vector<int>> arr;
int main() {
    su(n);
    su(m);
    arr.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            su(arr[i][j]);
            int mx = max(arr[i - 1][j], arr[i][j - 1]);
            if (arr[i][j] == 0) {
                arr[i][j] = mx + 1;
            } else if (mx >= arr[i][j]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}