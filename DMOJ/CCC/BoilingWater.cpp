// CCC '21 J1 - Boiling Water

#include <cstdio>

int b;
int main() {
    scanf("%d", &b);
    int p = 5 * b - 400;
    int lvl = 0;
    if (p < 100)
        lvl = 1;
    else if (p > 100)
        lvl = -1;
    printf("%d\n%d\n", p, lvl);
    return 0;
}