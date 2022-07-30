// Bill's Binoculars

#include <stdio.h>
#include <stdlib.h>

int n, k, a, b, c;
int main() {
    scanf("%d %d", &n, &k);
    long long *arr = malloc(sizeof(long long) * n);
    while (k--) {
        scanf("%d %d %d", &a, &b, &c);
        arr[a - 1] -= c;
        arr[b - 1] += c;
        for (int i = 0; i < n; i++) {
            printf("%lld ", arr[i]);
        }
        printf("\n");
    }
}
