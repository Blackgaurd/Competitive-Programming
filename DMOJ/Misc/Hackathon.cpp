// Hackathon

#include <stdio.h>

int n, k;
int main() {
    scanf("%d%d", &n, &k);
    while (k--) {
        int s, t, r;
        scanf("%d%d%d", &s, &t, &r);
        int h = n / s;
        if (h * s < n) h++;
        int l = (h - 1) / t;
        int ans = l * (t + r), cur = l * s * t;
        printf("%d %d\n", h, l);
    }

    return 0;
}