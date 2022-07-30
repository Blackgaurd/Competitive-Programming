// A Math Contest P7 - Factors
// https://math.stackexchange.com/questions/486864/computing-sums-of-divisors-in-o-sqrt-n-time

#include <math.h>
#include <stdio.h>
typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    ll ans = 0, lim = sqrt(n);
    for (ll k = 1; k <= lim; k++) {
        ans += n / k;
    }
    ans = 2 * ans - lim * lim;
    printf("%lld\n", ans);
}