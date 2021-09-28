// Uneven Sand

#include <stdio.h>
#include <string.h>

char str[7];
long long lo = 1, hi = 2e9;
int main() {
    while (1) {
        long long mid = (lo + hi) / 2;
        printf("%lld\n", mid);
        fflush(stdout);
        scanf("%s", str);
        if (strcmp(str, "SINKS") == 0)
            lo = mid + 1;
        else if (strcmp(str, "FLOATS") == 0)
            hi = mid - 1;
        else
            break;
    }
}