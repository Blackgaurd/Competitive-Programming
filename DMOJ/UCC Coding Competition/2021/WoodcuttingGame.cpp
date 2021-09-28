// UCC Coding Competition '21 P5 - Woodcutting Game
// partials

#include <bits/stdc++.h>
using namespace std;

const int MM = 303;
int h1, w1, h2, w2, dp[3][MM][3][MM];
int solve(int h1, int w1, int h2, int w2) {
    int &ret = dp[h1][w1][h2][w2];
    if (ret != -1) return ret;
    if (h1 == 1 && w1 == 1 && h2 == 1 && w2 == 1) return ret = 0;
    ret = 0;

    // option 1
    if (h1 == 2) ret |= !solve(1, w1, 1, w1);
    if (h2 == 2) ret |= !solve(1, w2, 1, w2);
    for (int i = 1; i < w1; i++) ret |= !solve(h1, i, h1, w1 - i);
    for (int i = 1; i < w2; i++) ret |= !solve(h2, i, h2, w2 - i);
    if (ret) return ret;

    // option 2
    if (h1 == 2) ret |= !solve(1, w1, h2, w2);
    if (h2 == 2) ret |= !solve(h1, w1, 1, w2);
    for (int i = 1; i <= 10 && i < w1; i++) ret |= !solve(h1, w1 - i, h2, w2);
    for (int i = 1; i <= 10 && i < w2; i++) ret |= !solve(h1, w1, h2, w2 - i);
    return ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d%d", &h1, &w1, &h2, &w2);
    printf("%c\n", (solve(h1, w1, h2, w2) ? 'W' : 'L'));

    return 0;
}