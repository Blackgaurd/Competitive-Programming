//

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
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

int n, arr[100005], mx = 1;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    scan(n);
    for (int i = 1; i <= n; i++) {
        scan(arr[i]);
    }
    int len = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i] <= arr[i - 1]) {
            len++;
            mx = max(mx, len);
            // cout << arr[i-1] << " " << arr[i] << nl;
        } else
            len = 1;
    }
    cout << mx;

    return 0;
}