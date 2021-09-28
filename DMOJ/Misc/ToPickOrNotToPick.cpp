// To pick or not to pick

#include <stdio.h>
#define su(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 48)                                           \
            ;                                                                  \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
    } while (0)
char _;

const int MM = 1e5 + 3;
int n, arr[MM], cnt[MM], dp[MM];
int main() {
    su(n);
    for (int i = 1; i <= n; i++) {
        su(arr[i]);
        cnt[arr[i]]++;
    }
    for (int i = 1; i <= n; i++) {
    }

    return 0;
}