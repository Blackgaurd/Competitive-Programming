// DMOPC '21 Contest 5 P3 - Permutations & Primes

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

const int MM = 1e5 + 3;
int n, t;
vector<bool> sieve, dp;
vector<int> prime;
int main() {
    sieve.resize(MM);
    for (int i = 2; i < MM; i++) {
        if (!sieve[i]) {
            prime.push_back(i);
            for (int j = i + i; j < MM; j += i) sieve[j] = true;
        }
    }
    dp.resize(MM);
    for (int i = 3; i < MM; i++) {
        for (int p : prime) {
            if (p + 1 > i) break;
            dp[i] = dp[i] || !dp[i - p];
        }
    }
    su(t);
    array<int, MM> a;
    while (t--) {
        su(n);
        if (n <= 2) {
            printf("-1\n");
            continue;
        }
        for (int i = 1; i <= n; i++) a[i] = i;
        int last = n;
        while (!dp[last]) last--;
        swap(a[last], a[n]);
        sort(a.begin() + last + 1, a.begin() + n + 1);
        for (int i = 1; i <= n; i++){
            printf("%d", a[i]);
            if (i != n) printf(" ");
        }
        printf("\n");
    }
}