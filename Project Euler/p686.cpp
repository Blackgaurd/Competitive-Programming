#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    double lo = log10(1.23), hi = log10(1.24), mult = log10(2);

    int n = 678910, j = 0, cnt = 0;
    while (cnt != n) {
        j++;
        double cur = j * mult - floor(j * mult);
        if (lo < cur && cur < hi) cnt++;
    }
    printf("%d\n", j);
}