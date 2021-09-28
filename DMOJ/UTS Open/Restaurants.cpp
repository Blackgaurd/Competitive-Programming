// UTS Open '18 P3 - Restaurants

#include <cstdio>
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 48)                                           \
            ;                                                                  \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
    } while (0)
char _;

int n, t, k, v, psa[(int)1e6 + 3], ans = 0;
int main() {
    su(n);
    su(t);
    su(k);
    su(v);
    for (int i = 0; i < v; i++) {
        int a;
        su(a);
        psa[a] = 1;
    }
    // set up first t elements
    int cnt = 0;
    for (int i = 1; i <= t; i++) cnt += psa[i];
    if (cnt < k) {
        for (int i = t; i >= 1; i--) {
            if (!psa[i]) {
                psa[i] = 1;
                cnt++;
                ans++;
            }
            if (cnt >= k) break;
        }
    }

    // do the rest
    for (int i = 1; i < t; i++) psa[i] += psa[i - 1];
    for (int i = t; i <= n; i++) {
        psa[i] += psa[i - 1];
        if (psa[i] - psa[i - t] < k) {
            psa[i]++;
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}