// St Robert Coding Competition J3 - Last Class

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <cstdio>

int main() {
    int a, n;
    scanf("%d%d", &a, &n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        if (x == a) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
}