// DMOPC '21 Contest 3 P1 - Sums & Differences

#include <bits/stdc++.h>
using namespace std;

const int MM = 1e4 + 3;
int n, ans[MM];
int query(int i, int j) {
    printf("? %d %d\n", i, j);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < (n - (n & 1)); i += 2) {
        int xmy = query(i, i + 1);  // value of x-y
        int n2y = query(i + 1, i);  // value of -2y
        ans[i + 1] = -n2y / 2;      // value of y
        ans[i] = xmy + ans[i + 1];  // value of x
    }
    if (n & 1) {
        int txmz = query(n - 1, n);  // value of 2x - z
        ans[n] = 2 * ans[n - 2] - txmz;
    }
    printf("!");
    for (int i = 1; i <= n; i++) {
        printf(" %d", ans[i]);
    }
    printf("\n");

    return 0;
}