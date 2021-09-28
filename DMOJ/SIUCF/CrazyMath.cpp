// Summer Institute '17 Contest 1 P5 - Crazy Math

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ll long long

const int mod = 1e9;
unordered_map<ll, ll> nums;
ll fib(ll n) {
    if (nums.find(n) != nums.end()) return nums[n];
    nums[n] =
        (fib((n - 1) / 2) * fib((n - 2) / 2) + fib(n / 2) * fib((n + 1) / 2)) %
        mod;
    return nums[n];
}

void gen() {
    int to = 1000;
    for (int i = 3; i <= to; i++) {
        nums[i] = nums[i - 1] + nums[i - 2];
        nums[i] %= mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll term;
    cin >> nums[0] >> nums[1] >> term;
    nums[2] = nums[1] + nums[0];
    gen();
    cout << fib(term) << nl;

    return 0;
}