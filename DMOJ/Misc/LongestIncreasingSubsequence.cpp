// Longest Increasing Subsequence

#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

#define sc(x)                                                                  \
    do {                                                                       \
        while ((x = getchar()) < 48)                                           \
            ;                                                                  \
        for (x -= 48; 48 <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - 48) \
            ;                                                                  \
    } while (0)
char _;

int n;
vector<int> lis = {-1};
int main() {
    sc(n);
    while (n--) {
        int a;
        sc(a);
        if (a > lis.back())
            lis.push_back(a);
        else if (a == lis.back())
            continue;
        else
            *lower_bound(lis.begin(), lis.end(), a) = a;
    }
    printf("%ld\n", lis.size() - 1);

    return 0;
}