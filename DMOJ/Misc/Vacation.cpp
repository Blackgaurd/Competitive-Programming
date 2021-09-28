// Vacation

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int n, arr[100005][3], ans = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        arr[i][0] = max(arr[i - 1][1], arr[i - 1][2]) + a;
        arr[i][1] = max(arr[i - 1][0], arr[i - 1][2]) + b;
        arr[i][2] = max(arr[i - 1][0], arr[i - 1][1]) + c;
    }
    ans = max(arr[n][0], arr[n][1]);
    ans = max(ans, arr[n][2]);
    printf("%d\n", ans);

    return 0;
}