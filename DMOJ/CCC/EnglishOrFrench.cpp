// CCC '11 S1 - English or French?

#include <bits/stdc++.h>
using namespace std;

int n, t = 0, s = 0;
int main() {
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        string str;
        getline(cin, str);
        for (char c : str) {
            if (c == 's' || s == 'S')
                s++;
            else if (c == 't' || c == 'T')
                t++;
        }
    }
    if (t <= s)
        cout << "French\n";
    else
        cout << "English\n";
    return 0;
}