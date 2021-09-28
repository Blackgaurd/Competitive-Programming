// Riolku's Mock CCC S1 - Word Bot

#include <bits/stdc++.h>
using namespace std;

int n, c, v, vcnt, ccnt;
string t;
bool vow = false, con = false;
bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
bool consta(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c >> v >> t;
    vow = vowel(t[0]);
    vcnt = vow;
    con = consta(t[0]);
    ccnt = con;
    for (int i = 1; i < n; i++) {
        if (t[i] == 'y') {
            vcnt++;
            ccnt++;
        } else if (vowel(t[i])) {
            vcnt++;
            con = false;
            ccnt = 0;
        } else if (consta(t[i])) {
            ccnt++;
            vow = false;
            vcnt = 0;
        }
        if (ccnt > c || vcnt > v) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}