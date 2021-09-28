// DWITE '07 R2 #1 - Not Quite Prime

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define scan(x)                                 \
    do {                                        \
        while ((x = getchar()) < '0')           \
            ;                                   \
        for (x -= '0'; '0' <= (_ = getchar());  \
             x = (x << 3) + (x << 1) + _ - '0') \
            ;                                   \
    } while (0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

bool prime[501], sem[1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    ms(prime, true, 501);
    prime[1] = false;
    for (int i = 4; i <= 500; i += 2) prime[i] = false;
    for (int i = 3; i <= 500; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= 500; j += i) prime[j] = false;
        }
    }
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            if (prime[i] && prime[j] && i * j <= 1000) sem[i * j] = true;
        }
    }
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        cout << ((sem[a]) ? "semiprime" : "not") << nl;
    }

    return 0;
}