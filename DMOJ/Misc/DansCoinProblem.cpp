// Dan's Coin Problem

#include <bits/stdc++.h>
using namespace std;
#define su(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 48)                                           \
            ;                                                                  \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
    } while (0)
#define si(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 45)                                           \
            ;                                                                  \
        _sign = x == 45;                                                       \
        if (_sign)                                                             \
            while ((x = getchar()) < 48)                                       \
                ;                                                              \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
        x = _sign ? -x : x;                                                    \
    } while (0)
char _;
bool _sign;

int t, n, dp[25003];
vector<int> a, coins;
bool make(int value) {
    if (coins.empty()) return false;
    int w = coins.back();
    for (int j = w; j <= value; j++) {
        dp[j] = min(dp[j], dp[j - w] + 1);
    }
    return dp[value] != 0x3f3f3f3f;
}
int main() {
    su(t);
    while (t--) {
        su(n);
        for (int i = 0; i < n; i++) {
            int x;
            su(x);
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0] = 0;
        for (int val : a) {
            if (!make(val)) {
                coins.push_back(val);
            }
        }
        printf("%d\n", coins.size());
        a.clear();
        coins.clear();
    }
}