// Brap Lesh Mafia

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
ll candies = 0;
int main() {
    scanf("%d%d", &n, &k);
    while (n--) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        candies += a * b;
        candies %= k;
    }
    printf("%lld\n", candies);

    return 0;
}