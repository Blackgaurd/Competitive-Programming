// Vera and LCS

#include <bits/stdc++.h>
using namespace std;

int n, k;
string a;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if (k > n) {
        cout << "WRONGANSWER\n";
        return 0;
    }
    cin >> a;
    cout << a.substr(0, k);
    for (int i = 0;) return 0;
}