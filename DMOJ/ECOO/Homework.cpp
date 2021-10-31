// ECOO '18 R2 P2 - Homework

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, double> pii;
#define TESTING 1

const int MM = 1e6 + 3;
int cases = 10;
int n;
pii arr[MM];
double ans[MM];
bool comp1(pii a, pii b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef TESTING
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    while (cases--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr + 1, arr + n + 1, comp1);
        priority_queue<double, vector<double>, greater<double>> q;
        int free = 0, pre = 0;
        for (int i = 1; i <= n; i++) {
            bool take = false;
            if (arr[i].first == pre) {
                if (free > 0) {
                    free--;
                    ans[i] = ans[i - 1] + arr[i].second;
                    take = true;
                } else {
                    double mn = q.top();
                    if (mn < arr[i].second) {
                        ans[i] = ans[i - 1] - mn + arr[i].second;
                        take = true;
                        q.pop();
                    } else {
                        ans[i] = ans[i - 1];
                    }
                }
            } else {
                free = arr[i].first - pre - 1;
                pre = arr[i].first;
                ans[i] = ans[i - 1] + arr[i].second;
                take = true;
            }
            if (take) q.push(arr[i].second);
        }
        cout << "ans: " << fixed << setprecision(4) << ans[n] << '\n';
    }

    return 0;
}