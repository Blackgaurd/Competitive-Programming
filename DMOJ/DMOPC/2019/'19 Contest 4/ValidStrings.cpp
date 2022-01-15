// DMOPC '19 Contest 4 P1 - Valid Strings

#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--) {
        string t, valid = "YES\n";
        cin >> t;
        int cnt = 0;
        for (char c : t) {
            if (c == '(')
                cnt++;
            else if (c == ')')
                cnt--;
            if (cnt < 0) {
                valid = "NO\n";
                break;
            }
        }
        if (cnt != 0) valid = "NO\n";
        cout << valid;
    }
    return 0;
}