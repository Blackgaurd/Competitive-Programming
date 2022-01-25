// Counting Bits

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll n, ans;
pii divmod(ll a, ll b) {
    return {a / b, a % b};
}
int main() {
    cin >> n;
    for (int i = 0; i <= 50; i++) {
        auto [a, b] = divmod(n + 1, 1LL << (i + 1));
        ans += a * (1LL << i);
        b -= (1LL << i);
        if (b > 0) ans += b;
    }
    cout << ans << '\n';
}