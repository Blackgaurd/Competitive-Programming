// Bob's Reverse Number

#include <bits/stdc++.h>
using namespace std;

string a, b;
int main() {
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << min(stoll(a), stoll(b)) << '\n';

    return 0;
}