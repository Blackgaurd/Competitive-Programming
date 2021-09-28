// Prefix Digits

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define watch(x) cout << (#x) << ": " << x << '\n'

int t;
string sn, sk;
ll n, k, modn, modk;
ll pow10[] = {1,      10,      100,      1000,      10000,
              100000, 1000000, 10000000, 100000000, 1000000000};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (cin >> t; t--;) {
        cin >> sn >> sk;

        n = stoll(sn);
        k = stoll(sk);
        if ((n ^ k) & 1) {  // if partities of n and k are different
            printf("NO\n");
            continue;
        }

        modn = pow10[sn.size()];
        modk = pow10[sk.size()];

        ll cur = k;
        while (true) {
            if (cur == n) {
                printf("YES\n");
                break;
            }
            cur *= k;
            if (cur > modn && cur % modk == k) {
                printf("NO\n");
                break;
            }
            cur %= modn;
        }
    }

    return 0;
}