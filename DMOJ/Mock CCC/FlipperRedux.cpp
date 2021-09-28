// Mock CCC '20 S2 - Flipper Redux

#include <stdio.h>

#include <utility>
#include <vector>
using namespace std;

#define su(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 48)                                           \
            ;                                                                  \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
    } while (0)
#define sb(x)                        \
    do {                             \
        while ((_ = getchar()) < 48) \
            ;                        \
        x = (_ - 48);                \
    } while (0)
char _;

// use 01 knapsack (flip or dont for each row/col)
const int MM = 2e3 + 3;
int n;
bool arr[MM][MM], rf[MM], cf[MM];
vector<pair<char, int>> coms;
int main() {
    su(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sb(arr[i][j]);
        }
    }

    for (auto i : coms) {
        printf("%c %d\n", i.first, i.second);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf(arr[i][j] ? "1 " : "0 ");
        printf("\n");
    }

    return 0;
}
