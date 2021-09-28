// ECOO '21 P1 - Many Messages

#include <stdio.h>

int a, b, c, i;
int main() {
    scanf("%d%d%d", &a, &b, &c);
    a += b;
    for (i = 1; a < c; a += b, i++)
        ;
    if (i > 3)
        printf("Who knows...\n");
    else
        printf("%d\n", a);

    return 0;
}