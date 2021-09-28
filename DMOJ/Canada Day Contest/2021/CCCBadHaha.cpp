// Canada Day Contest 2021 - CCC Bad Haha

#include <bits/stdc++.h>
using namespace std;

int t, n, k;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (cin >> t; t--;) {
        string num;
        vector<int> cnt(10);
        char c;
        while ((c = getchar()) != '\n') {
            cnt[c - '0']++;
            num += c;
        }
    }

    return 0;
}