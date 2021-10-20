// A. Windblume Ode

#include <bits/stdc++.h>
using namespace std;
// clang-format off
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
// clang-format on

const int MM = 103;
int t, n, arr[MM];
bool prime(int x) {
    if (x & 1) {
        for (int i = 3; i * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }
    return false;
}
int main() {
    su(t);
    while (t--) {
        su(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            su(arr[i]);
            sum += arr[i];
        }
        if (prime(sum)) {
            printf("%d\n", n - 1);
            bool flag = true;
            for (int i = 0; i < n; i++) {
                if (flag && arr[i] & 1) {
                    flag = false;
                    continue;
                }
                printf("%d ", i + 1);
            }
        } else {
            printf("%d\n", n);
            for (int i = 0; i < n; i++) {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
    }

    return 0;
}