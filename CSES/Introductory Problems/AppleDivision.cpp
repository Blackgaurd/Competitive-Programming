// Apple Division

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

long long ans = 2e10;
vector<int> arr, left, right;
long long sum(vector<int> &arr) {
    long long ret = 0;
    for (int i : arr) ret += i;
    return ret;
}
void solve(int i) {
    if (i == arr.size()) {
        ans = min(ans, abs(sum(left) - sum(right)));
        return;
    }
    left.push_back(arr[i]);
    solve(i + 1);
    left.pop_back();
    right.push_back(arr[i]);
    solve(i + 1);
    right.pop_back();
}
int main() {
    int n;
    scanf("%d", &n);
    arr.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    solve(0);
    printf("%lld\n", ans);

    return 0;
}