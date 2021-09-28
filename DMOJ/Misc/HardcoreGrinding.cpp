// Hardcore Grinding

#include <algorithm>
#include <cstdio>
using namespace std;
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

int n, psa[(int)1e7 + 3], maxf = 0, ans = 0;
int main() {
    su(n);
    for (int i = 0; i < n; i++) {
        int s, f;
        su(s);
        su(f);
        psa[s]++;
        psa[f]--;
        maxf = max(maxf, f);
    }
    for (int i = 1; i <= maxf; i++) {
        psa[i] += psa[i - 1];
        ans = max(ans, psa[i]);
    }
    printf("%d\n", ans);

    return 0;
}