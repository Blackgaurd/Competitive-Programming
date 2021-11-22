// A. Linear Keyboard

#include <stdio.h>

int abs(int x) {
    if (x < 0) return -x;
    return x;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, pos[26];
    char c, c2;
    scanf("%d\n", &n);
    while (n--) {
        int cnt = 0, ans = 0;
        while ((c = getchar()) != '\n') {
            pos[c - 'a'] = cnt++;
        }
        c = getchar();
        while ((c2 = getchar()) != '\n') {
            ans += abs(pos[c2 - 'a'] - pos[c - 'a']);
            c = c2;
        }
        printf("%d\n", ans);
    }

    return 0;
}
