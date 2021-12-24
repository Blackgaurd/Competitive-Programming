// Tower of Hanoi

#include <stdio.h>

void hanoi(int n, char start, char end, char tmp) {
    if (n == 1) {
        printf("%c %c\n", start, end);
        return;
    }
    hanoi(n - 1, start, tmp, end);
    printf("%c %c\n", start, end);
    hanoi(n - 1, tmp, end, start);
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1 << n) - 1);
    hanoi(n, '1', '3', '2');
}