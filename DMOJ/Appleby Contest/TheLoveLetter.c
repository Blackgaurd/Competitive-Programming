// Appleby Contest '19 P2 - The Love Letter

#include <stdio.h>

int n, l;
int c;
int main() {
    scanf("%d%d\n", &n, &l);
    while ((c = getchar()) != '\n') {
        if (c == ' ')
            putchar(c);
        else {
            c += l;
            while (c > 'z') c -= 26;
            putchar(c);
        }
    }
}
