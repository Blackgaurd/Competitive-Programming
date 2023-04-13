#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n = 600851475143;
int main() {
    for (ll i=2; i*i<=n; i++) {
        while (n % i == 0) n/= i;
    }
    printf("%lld\n", n);
}