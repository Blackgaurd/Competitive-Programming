// DMOPC '20 Contest 6 P2 - Interpretive Art

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define watch(x) cout << (#x) << ": " << x << '\n'

const int MM = 5e5 + 3;
int n;
bool a[MM], b[MM];
vector<pii> ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = n - 1; i >= 0; i--) {
        if (b[i]) {
            if (a[i]) continue;
            int cnt = 1, j;
            for (j = i - 1; j >= 0; j--) {
                if (a[j]) cnt--;
                if (b[j]) {
                    if (!b[j + 1] && j + 1 != i) {
                        cout << "-2\n";
                        return 0;
                    }
                    cnt++;
                }
                if (!cnt) {
                    ans.emplace_back(j, i + 1);
                    i = j;
                    break;
                }
            }
            if (!j) i = -1;
        } else if (a[i]) {
            // watch(i);
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans.size() << '\n';
    for (pii &p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}