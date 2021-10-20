// D. Training Session

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

const int MM = 2e5 + 3;
int t, n, ans, arr[2][MM], freq[2][MM];
void reset() {
    ans = 0;
    memset(freq, 0, sizeof(freq));
}
int main() {
    su(t);
    while (t--) {
        su(n);
        for (int i = 0; i < n; i++) {
            su(arr[0][i]);
            su(arr[1][i]);
            freq[0][arr[0][i]]++;
            freq[1][arr[1][i]]++;
        }
        for (int i = n - 1, ttl; i >= 2; i--) {
            //! might have to make ttl long long
            freq[0][arr[0][i]]--;
            freq[1][arr[1][i]]--;

            // repeat neither
            ttl = max(i - freq[0][arr[0][i]] - freq[1][arr[1][i]], 0);
            printf("ttl1: %d\n", ttl);
            ans += (ttl * (ttl - 1)) / 2;

            // repeat 0
            if (freq[0][arr[0][i]]){
                ttl = i - freq[1][arr[1][i]];
                printf("ttl2: %d\n", ttl);
                ans += (ttl * (ttl - 1)) / 2;
            }

            // repeat 1
            if (freq[1][arr[1][i]]){
                ttl = i - freq[0][arr[0][i]];
                printf("ttl3: %d\n", ttl);
                ans += (ttl * (ttl - 1)) / 2;
            }

            printf("\n");
        }
        printf("%d\n", ans);
        reset();
    }

    return 0;
}

