// COCI '14 Contest 2 #2 Utrka

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n;
unordered_map<string, int> names;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < 2 * n - 1; i++) {
        string a;
        cin >> a;
        if (names[a])
            names[a]++;
        else
            names[a] = 1;
    }
    for (auto p : names) {
        if (p.second % 2) {
            cout << p.first << nl;
            break;
        }
    }

    return 0;
}