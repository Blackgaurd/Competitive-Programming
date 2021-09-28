// Another Contest 8 Problem 3 - Replay Double Ignition
// max pisano = 375,000

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
typedef long long ll;
typedef unsigned long long ull;

int m, q;
ll n;
string t;
unordered_map<int, ll> nums;
ll pisano(ll m) {
    ll a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return -1;
}
ull helper(int n) {
    if (n <= 1) return 1;
    if (nums.find(n) != nums.end()) return nums[n];
    nums[n] = (helper((n - 1) / 2) * helper((n - 2) / 2) +
               helper(n / 2) * helper((n + 1) / 2)) % m;
    return nums[n];
}
ull fib(int n) { return helper(n - 1); }
int main() {
    su(m);
    su(q);
    ll period = pisano(m);
    for (ll i = 1; i <= period; i++) {
        t += to_string(fib(i));
    }
    while (q--) {
        int a;
        su(a);
        printf("%c\n", t[(a - 1) % t.size()]);
    }

    return 0;
}