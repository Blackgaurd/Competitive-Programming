// Split Array

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = queue<int>;
using qpii = queue<pii>;

const int MM = 1e5 + 5;
int n, nums[MM], pre[MM], suf[MM], sol = INT_MAX;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    pre[1] = nums[1];
    suf[n - 1] = nums[n];
    for (int i = 2; i < n; i++) pre[i] = pre[i - 1] + nums[i];
    for (int i = n - 2; i >= 1; i--) suf[i] = suf[i + 1] + nums[i + 1];
    for (int i = 1; i < n; i++) sol = min(sol, abs(pre[i] - suf[i]));
    cout << sol;

    return 0;
}