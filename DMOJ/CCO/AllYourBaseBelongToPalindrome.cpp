// CCO '13 P1 - All Your Base Belong to Palindromes

#include <bits/stdc++.h>
using namespace std;

int x;
bool check(int b) {
    vector<int> p;
    int tmp = x;
    while (tmp) {
        p.push_back(tmp % b);
        tmp /= b;
    }
    for (int i = 0, j = p.size() - 1; i < j; i++, j--) {
        if (p[i] != p[j]) return false;
    }
    return true;
}
int main() {
    scanf("%d", &x);
    for (int i = 2; i * i <= x; i++) {
        if (check(i)) {
            printf("%d\n", i);
        }
    }
    for (int i = sqrt(x); i >= 1; i--) {
        if (i * i == x) continue;
        int other = x / i - 1;
        if (x % i == 0 && other != 1 && (double)other > sqrt(x)) {
            printf("%d\n", other);
        }
    }
}
