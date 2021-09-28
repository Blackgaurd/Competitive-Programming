// Autocomplete
// solved using string hashing

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll base = 131, MOD = 1e12 + 3;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int _case = 1; _case <= t; _case++) {
        int n, ans = 0;
        cin >> n;
        unordered_set<ull> prefixes;
        while (n--) {
            string s;
            cin >> s;
            ull hsh = 0;
            int i = 0;
            for (; i < s.size(); i++) {
                hsh = (hsh * base + s[i]) % MOD;
                ans++;
                if (prefixes.find(hsh) == prefixes.end()) {
                    prefixes.insert(hsh);
                    break;
                }
            }
            for (i++; i < s.size(); i++) {
                hsh = (hsh * base + s[i]) % MOD;
                prefixes.insert(hsh);
            }
        }
        cout << "Case #" << _case << ": " << ans << '\n';
    }

    return 0;
}
