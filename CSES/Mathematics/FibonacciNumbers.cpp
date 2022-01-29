// Fibonacci Numbers

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
const ll mod = 1e9 + 7;
unordered_map<ll, ll> nums;

ll fib(ll n) {
    if (n <= 1) return 1;
    if (nums.find(n) != nums.end()) return nums[n];
    nums[n] =
        (fib((n - 1) / 2) * fib((n - 2) / 2) + fib(n / 2) * fib((n + 1) / 2)) %
        mod;
    return nums[n];
}
int main() {
    ll n;
    scanf("%lld", &n);
    if (n == 0){
        printf("0\n");
        return 0;
    }
    printf("%lld\n", fib(n - 1));
}