// B. A Perfectly Balanced String?

#include <bits/stdc++.h>
using namespace std;

const int MM = 3e5 + 3;
int t, ptr;
string s;
int psa[26][MM];
char get(int i) {
    return s[i - 1];
}
bool solve() {
    unordered_set<int> contain;
    vector<int> last(26, -1);
    for (int i = 0; i < 26; i++) psa[i][ptr] = 0;
    for (char c : s) contain.insert(c - 'a');
    for (int r = 1; r <= s.size(); r++) {
        int c = get(r) - 'a';
        psa[c][r + ptr]++;
        for (int i : contain) {
            psa[i][r + ptr] += psa[i][r + ptr - 1];
        }

        if (last[c] == -1) {
            last[c] = r;
            continue;
        }

        int l = last[c];
        for (int i : contain) {
            if (i == c) continue;
            if (psa[i][l + ptr - 1] == psa[i][r + ptr]) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        cout << (solve() ? "no" : "yes") << '\n';
        ptr += s.size();
    }
}