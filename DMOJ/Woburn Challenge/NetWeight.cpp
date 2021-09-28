// WC '18 Contest 3 J2 - Net Weight

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (a <= 100) nums.push_back(a);
    }
    nums.push_back(0);
    nums.push_back(0);
    sort(nums.begin(), nums.end());
    cout << (nums[nums.size() - 1] + nums[nums.size() - 2]) << '\n';

    return 0;
}