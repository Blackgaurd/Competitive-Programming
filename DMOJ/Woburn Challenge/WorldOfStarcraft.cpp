// WC '18 Contest 4 S1 - World of StarCraft

#include <bits/stdc++.h>
using namespace std;
#define sc(x)                                   \
    do {                                        \
        while ((x = getchar()) < '0')           \
            ;                                   \
        for (x -= '0'; '0' <= (_ = getchar());  \
             x = (x << 3) + (x << 1) + _ - '0') \
            ;                                   \
    } while (0)
char _;

const int MM = 1e5 + 5;
int n, m, k, p[MM], ans = 0;
string planets;
int flead(int x) {
    if (p[x] != x) p[x] = flead(p[x]);
    return p[x];
}
int main() {
    sc(n);
    sc(m);
    sc(k);
    cin >> planets;
    for (int i = 1; i < MM; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        sc(a);
        sc(b);
        if (planets[a - 1] == planets[b - 1]) {
            p[flead(a)] = flead(b);
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        sc(a);
        sc(b);
        if (flead(a) == flead(b)) ans++;
    }
    printf("%d\n", ans);

    return 0;
}