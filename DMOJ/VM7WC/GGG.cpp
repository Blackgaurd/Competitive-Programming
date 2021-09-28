// VM7WC '16 #2 Gold - GGG

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define su(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 48)                                           \
            ;                                                                  \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
    } while (0)
char _;

const int MM = 1e6 + 3;
int n, m, pos[MM];
vector<int> lis = {-1};
int main() {
    su(n);
    for (int i = 1; i <= n; i++) {
        int a;
        su(a);
        pos[a] = i;
    }
    su(m);
    for (int i = 1; i <= m; i++) {
        int a;
        su(a);
        a = pos[a];
        if (!a) continue;
        if (a > lis.back())
            lis.push_back(a);
        else
            *lower_bound(lis.begin(), lis.end(), a) = a;
    }
    printf("%d\n", lis.size() - 1);

    return 0;
}