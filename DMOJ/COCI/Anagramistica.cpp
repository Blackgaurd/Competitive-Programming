// COCI '20 Contest 6 #3 Anagramistica

#include <bits/stdc++.h>
using namespace std;

int n, k;
unordered_map<string, int> cnt;
ostream& operator<<(ostream &s, unordered_map<string, int> lol) {
    s << "{";
    for (auto [a, b]: lol) s << a << ": " << b << ", ";
    s << "}";
    return s;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++){
        string a;
        cin >> a;
        sort(a.begin(), a.end());
        cnt[a]++;
    }
    cout << cnt;
}