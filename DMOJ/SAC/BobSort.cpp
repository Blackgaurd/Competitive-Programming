// SAC '22 Code Challenge 3 P3 - Bob Sort

#include <bits/stdc++.h>
using namespace std;

int n, i = 1;
vector<int> arr;
int main() {
    cin >> n;
    arr.resize(n);
    int mx = 0;
    for (auto &t : arr) {
        cin >> t;
        mx = max(mx, int(to_string(t).size()));
    }
    for (; i <= mx; i++) {
        auto cmp = [](int a, int b) {
            int mod = pow(10, i);
            return a % mod < b % mod;
        };
        sort(arr.begin(), arr.end(), cmp);
        for (int j = 0; j < n; j++) cout << arr[j] << " \n"[j + 1 == n];
    }
}