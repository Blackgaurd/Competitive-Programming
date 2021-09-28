// CCC '21 S1 - Crazy Fencing

#include <stdio.h>

int n, arr[10003], ans = 0;
int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        ans += (arr[i] + arr[i + 1]) * a;
    }
    if (ans & 1)
        printf("%d.5\n", ans >> 1);
    else
        printf("%d\n", ans >> 1);

    return 0;
}