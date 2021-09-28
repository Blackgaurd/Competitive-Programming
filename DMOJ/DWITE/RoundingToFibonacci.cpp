// DWITE '09 R3 #2 - Rounding to Fibonacci

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

const ll mod = 1e11;
unordered_map<unsigned long long, ll> nums;
unsigned long long fib(unsigned long long n) {
    if (n <= 1) return 1;
    if (nums.find(n) != nums.end()) return nums[n];
    // multiply matrix by previous 2 terms
    // 0 1
    // 1 1
    nums[n] =
        (fib((n - 1) / 2) * fib((n - 2) / 2) + fib(n / 2) * fib((n + 1) / 2)) %
        mod;
    return nums[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    // maximum = 45
    nums[1] = 1;
    for (int i = 2; i <= 44; i++) fib(i);
    // for (int i=0; i<=44; i++) cout << i << ": " << nums[i] << nl;
    for (int k = 0, a; k < 5; k++) {
        cin >> a;
        if (!a) {
            cout << a << nl;
            continue;
        }
        for (int i = 0; i <= 45; i++) {
            if (a == nums[i]) {
                cout << a << nl;
                break;
            }
            if (nums[i] > a) {
                if (nums[i] - a <= a - nums[i - 1])
                    cout << nums[i] << nl;
                else
                    cout << nums[i - 1] << nl;
                break;
            }
        }
    }
    return 0;
}