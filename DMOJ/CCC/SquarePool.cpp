// CCC '22 J5 - Square Pool

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, t, ans = 0;
vector<pii> trees;
int main() {
    cin >> n >> t;
    for (int i = t, a, b; i--;) {
        cin >> a >> b;
        trees.emplace_back(a, b);
    }
    trees.emplace_back(0, 0);
    trees.emplace_back(n + 1, n + 1);

    for (auto [x1, y1] : trees) {
        for (auto [x2, y2] : trees) {
            int left = min(y1, y2), right = max(y1, y2);
            vector<int> inside = {0, n + 1};
            for (auto [x3, y3] : trees) {
                if (left < y3 && y3 < right) {
                    inside.push_back(x3);
                }
            }

            int max_height = 0;
            sort(inside.begin(), inside.end());
            for (int i = 1; i < inside.size(); i++) {
                int top = inside[i - 1], bottom = inside[i];
                max_height = max(max_height, bottom - top - 1);
            }

            int max_width = right - left - 1;
            int side_length = min(max_width, max_height);

            ans = max(ans, side_length);
        }
    }

    cout << ans << '\n';
}
