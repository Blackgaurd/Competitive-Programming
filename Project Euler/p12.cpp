#include <bits/stdc++.h>
using namespace std;

int num_factors(int x) {
    unordered_map<int, int> factors;
    int cop = x;
    for (int i = 2; i * i <= cop; i++) {
        while (x % i == 0) {
            x /= i;
            factors[i] += 1;
        }
    }
    if (x != 1) factors[x] += 1;

    int num = 1;
    for (auto [f, e] : factors) {
        num *= e + 1;
    }
    return num;
}
int main() {
    for (int n = 1;; n++) {
        if (num_factors(n * (n + 1) / 2) > 500) {
            cout << n * (n + 1) / 2 << '\n';
            break;
        }
    }
}