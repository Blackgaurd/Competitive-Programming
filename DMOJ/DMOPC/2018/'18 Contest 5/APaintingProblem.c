// DMOPC '18 Contest 5 P1 - A Painting Problem

#include <stdio.h>

int n, m, k, b, p;
int main() {
    scanf("%d %d %d", &n, &m, &k);
    while (k--) (1 << k) & (n ^ m) ? b++ : p++;
    printf("%d %d\n", b, p);
}