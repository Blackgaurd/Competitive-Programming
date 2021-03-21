#include <stdio.h>

int main() {
    unsigned long long a, b, c, mod = 42069900169420;
    scanf("%llu%llu%llu", &a, &b, &c);
    unsigned long long ans = (a+b+c)%mod;
    printf("%llu\n", ans);
    return 0;
}