// UTS Open '21 P2 - Prime Array

#include <stdio.h>

int k, arr[100];
int fn(int n) {
    return n * (n - 1) / 2;
}
int main() {
    scanf("%d", &k);
    int len;
    for (int i = 1; i <= 101; i++) {
        if (fn(i) > k) {
            len = i;
            break;
        }
    }
    len--;
    for (int i = 0, x = 0; i < len; i++) {
        arr[i] = (x ^= 1) + 2;
    }
    int cnt = fn(len);
    for (int i = 0; i < k - cnt; i++) {
        arr[i] = 1;
    }
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}