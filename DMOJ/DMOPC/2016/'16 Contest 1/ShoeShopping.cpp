// DMOPC '16 Contest 1 P3 - Shoe Shopping

#include <bits/stdc++.h>
using namespace std;

int n, arr[10003];
double dp[10003];
double two(int a, int b) { return max(a, b) + (double)min(a, b) / (double)2; }
int three(int a, int b, int c) { return a + b + c - min({a, b, c}); }
int main() {
    scanf("%d%d%d", &n, &arr[1], &arr[2]);
    dp[1] = arr[1];
    dp[2] = max(arr[1], arr[2]) + (double)min(arr[1], arr[2]) / (double)2;

    for (int i = 3; i <= n; i++) {
        scanf("%d", &arr[i]);
        double buytwo = dp[i - 2] + two(arr[i], arr[i - 1]),
               buythree = dp[i - 3] + three(arr[i], arr[i - 1], arr[i - 2]),
               buyone = dp[i - 1] + arr[i];
        dp[i] = min({buyone, buytwo, buythree});
    }

    printf("%.1f\n", dp[n]);
    return 0;
}