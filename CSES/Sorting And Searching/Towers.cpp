// Towers

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> towers;
int main() {
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        if (towers.empty() || a >= towers.back()){
            towers.push_back(a);
            continue;
        }
        auto iter = upper_bound(towers.begin(), towers.end(), a);
        *iter = a;
    }
    cout << towers.size() << '\n';
}