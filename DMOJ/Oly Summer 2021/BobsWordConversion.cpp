// Bob's Word Conversion

#include <bits/stdc++.h>
using namespace std;

string a, b;
int main() {
    cin >> b >> a;
    if (b.length() - a.length() > 1) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0, cnt = 0; i < a.length(); i++) {
        if (a[i] == b[i + cnt]) continue;
        cnt++;
        if (cnt == 2) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}