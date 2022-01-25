// COCI '06 Contest 6 #2 Magija

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

int n, m, a, b;
int main() {
    su(n);
    su(m);
    vector<vector<char>> arr(2 * n, vector<char>(2 * m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sc(arr[i][j]);
            int fn = 2 * n - i - 1, fm = 2 * m - j - 1;
            arr[fn][j] = arr[i][fm] = arr[fn][fm] = arr[i][j];
        }
    }
    su(a);
    su(b);
    arr[a - 1][b - 1] = arr[a - 1][b - 1] == '.' ? '#' : '.';
    for (auto &r : arr) {
        for (auto &c : r)
            printf("%c", c);
        printf("\n");
    }
}