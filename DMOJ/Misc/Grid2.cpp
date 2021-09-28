// Grid 2

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int mod = 1e9 + 7;
int h, w, n, pre[1000003], cur[1000003], ind = 0;
set<pii> block;
void print(int arr[]) {
    for (int i = 1; i <= w; i++) cout << arr[i] << ' ';
    cout << '\n';
}
int main() {
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        block.insert({a, b});
    }
    cur[0] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (block.count({i, j}))
                cur[j] = 0;
            else {
                int left = (block.count({i, j - 1}) ? 0 : cur[j - 1]);
                int up = (block.count({i - 1, j}) ? 0 : pre[j]);
                cur[j] = left + up;
                cur[j] %= mod;
            }
        }
        cur[0] = 0;
        // cout << "pre: ";
        // print(pre);
        // cout << "cur: ";
        // print(cur);
        swap(pre, cur);
    }
    cout << pre[w] << '\n';

    return 0;
}