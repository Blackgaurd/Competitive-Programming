// CCC '16 S4 - Combining Riceballs

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

int n, arr[403], psa[403], ans = 0;
bool dp[403][403];
int sum(int start, int end) {
    if (start == end) return arr[start];
    return psa[end] - psa[start - 1];
}
int main() {
    su(n);
    for (int i = 1; i <= n; i++) {
        su(arr[i]);
        ans = max(ans, arr[i]);
        psa[i] = psa[i - 1] + arr[i];
        dp[i][i] = true;
    }
    for (int i = 1; i + 1 <= n; i++) {
        if (arr[i] == arr[i + 1]) {
            dp[i][i + 1] = true;
            ans = max(ans, sum(i, i + 1));
        }
    }
    for (int len = 2; len <= n - 1; len++) {
        for (int i = 1; i + len <= n; i++) {
            int j = i + len;
            bool flag = true;
            for (int mid = i; mid <= j - 1; mid++) {
                if (dp[i][mid] && dp[mid + 1][j] &&
                    (sum(i, mid) == sum(mid + 1, j))) {
                    dp[i][j] = true;
                    flag = false;
                    break;
                }
            }
            for (int p = i; p <= j - 2; p++) {
                if (flag) {
                    for (int q = p + 2; q <= j; q++) {
                        if (dp[i][p] && dp[p + 1][q - 1] && dp[q][j] &&
                            (sum(i, p) == sum(q, j))) {
                            dp[i][j] = true;
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (dp[i][j]) ans = max(ans, sum(i, j));
        }
    }

    printf("%d\n", ans);

    return 0;
}
