// Dice Combinations

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, MM = 1e6 + 3;
int mem[MM];
int solve(int x) {
    if (x <= 1) return x;
    if (mem[x] != 0) return mem[x];
    int &ret = mem[x];
    ret += x <= 6;
    for (int i = 1; i <= min(x - 1, 6); i++) {
        ret = (ret + solve(x - i)) % MOD;
    }
    return ret %= MOD;
}
int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", solve(x));
}