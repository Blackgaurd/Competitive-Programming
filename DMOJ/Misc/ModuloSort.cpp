// Modulo Sort

#include <algorithm>
#include <cstdio>

int n, k, arr[100000];
bool comp(int a, int b) {
    if (a % k == b % k) return a < b;
    return a % k < b % k;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr + n, comp);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}