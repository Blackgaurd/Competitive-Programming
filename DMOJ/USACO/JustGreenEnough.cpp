//

#include <bits/stdc++.h>
using namespace std;

int n, a[203][203], h[203];
long long count(int m) {
    memset(h, 0, sizeof(h));
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] >= m)
                h[j]++;
            else
                h[j] = 0;
        }
        for (int j = 1; j <= n; j++) {
            int cnt = h[j], low = h[j];
            for (int k = j - 1; k >= 1; k--) {
                low = min(low, h[k]);
                cnt += low;
            }
            ans += cnt;
        }
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%lld\n", count(100) - count(101));

    return 0;
}