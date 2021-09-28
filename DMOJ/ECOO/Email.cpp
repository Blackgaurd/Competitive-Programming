// ECOO '19 R2 P1 - Email

#include <bits/stdc++.h>
using namespace std;

int cases = 1;
int t;
string cur;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cases--) {
        cin >> t;
        set<string> seen;
        while (t--) {
            cin >> cur;
            string parsed = "";
            bool plus = false, at = false;
            for (char c : cur) {
                if (!at) {
                    if (c == '.') continue;
                    if (c == '@')
                        at = true;
                    else if (c == '+') {
                        plus = true;
                        continue;
                    } else if (plus)
                        continue;
                }
                parsed += tolower(c, locale());
            }
            seen.insert(parsed);
        }
        cout << seen.size() << '\n';
    }

    return 0;
}