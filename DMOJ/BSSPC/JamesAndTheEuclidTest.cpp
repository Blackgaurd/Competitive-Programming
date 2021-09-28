// BSSPC '21 J5 - James and the Euclid Test

#include <bits/stdc++.h>
using namespace std;

const int MM = 1e6, MN = 1e6;
int q, x, k, psa[MN];
bool p[MM];
vector<int> primes = {2};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    psa[2] = 2;
    for (int i = 4; i < MM; i += 2) p[i] = true;
    for (int i = 3; i < MM; i += 2) {
        if (!p[i]) {
            primes.push_back(i);
            psa[i] = i;
            for (int j = i * 2; j < MM; j += i) p[j] = true;
        }
    }
    for (int i = 1; i < MN; i++) psa[i] += psa[i - 1];
    cin >> q;
    while (q--) {
        cin >> x >> k;
        int it = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
        int first = primes[it], last = primes[it + k - 1];
        cout << last << ' ' << psa[last] - psa[first - 1] << '\n';
    }

    return 0;
}