// UCC Coding Competition '20 P1 - Snowstorm

#include <stdio.h>

int n, ans = 0;
char a[1003], b[1003];
int main() {
    scanf("%d%s%s", &n, a, b);
    for (int i = 0; i < n; i++)
        if (a[i] == '0' && b[i] == '0') ans++;
    printf("%d\n", ans);

    return 0;
}