#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 1000;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            int c = 1000 - a - b;
            if (c * c == a * a + b * b) {
                printf("%d\n", a * b * c);
            }
        }
    }
}