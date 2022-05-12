// A. Subtle Substring Subtraction

#include <bits/stdc++.h>
using namespace std;

int n;
string t;
int sum() {
    int ret = 0;
    for (char c : t) {
        ret += c - 'a' + 1;
    }
    return ret;
}
int main() {
    cin >> n;
    while (n--) {
        cin >> t;
        int ttl = sum();
        if (t.size() == 1) {
            cout << "Bob " << ttl << '\n';
        } else if (t.size() % 2 == 1) {
            int f = t[0] - 'a' + 1;
            int l = t.back() - 'a' + 1;
            cout << "Alice " << max(ttl - 2 * f, ttl - 2 * l) << '\n';
        } else {
            cout << "Alice " << ttl << '\n';
        }
    }
}