#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// partials
const ull MM = 1e18 + 3;
int n;
ull increment(ull a, ull b) {  // a < b
    ull cnt = 0;
    while (a != b) {
        if (b & 1)
            b--;
        else if (b / 2 >= a)
            b /= 2;
        else
            b--;
        cnt++;
    }
    return cnt;
}
ull solve(ull a, ull b) {  // a > b
    ull cnt = 0;
    ull ans = LLONG_MAX;
    while (a >= 2) {
        if (a & 1)
            a++;
        else {
            a /= 2;
            if (a <= b) ans = min(ans, increment(a, b) + cnt);
        }
        cnt++;
    }
    return ans + 1;
}
int main() {
    int n;
    cin >> n;
    while (n--){
        ull a, b;
        cin >> a >> b;
        if (a == b) cout << 0 << '\n';
        else if (a > b) cout << solve(a, b) << '\n';
        else cout << increment(a, b) << '\n';
    }
}
