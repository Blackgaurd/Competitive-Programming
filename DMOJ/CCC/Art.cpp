// CCC '20 J3 - Art

#include <bits/stdc++.h>
using namespace std;

int n, maxx = 0, maxy = 0, minx = 100, miny = 100;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--) {
        int a, b;
        string t;
        cin >> t;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == ',') {
                a = stoi(t.substr(0, i));
                b = stoi(t.substr(i + 1, t.size() - i));
                break;
            }
        }
        maxx = max(maxx, a);
        minx = min(minx, a);
        maxy = max(maxy, b);
        miny = min(miny, b);
    }
    cout << minx - 1 << ',' << miny - 1 << '\n';
    cout << maxx + 1 << ',' << maxy + 1 << '\n';

    return 0;
}