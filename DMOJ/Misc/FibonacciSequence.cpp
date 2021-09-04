// Fibonacci Sequence

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
using qi = queue<int>;
using qpii = queue<pii>;
#define ms memset;

unsigned long long n;
const ll mod = 1e11+7;
unordered_map<unsigned long long, ll> nums;

unsigned long long fib(unsigned long long n){
    if (n<=1) return 1;
    if (nums.find(n)!=nums.end()) return nums[n];
    nums[n] = (fib((n-1)/2)*fib((n-2)/2)+fib(n/2)*fib((n+1)/2))%mod;
    return nums[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    // shift number back one
    // because function starts from 1, 2, 3, 5 ...
    cout << fib(n-1);

    return 0;
}