// Concert Tickets

#include <bits/stdc++.h>
using namespace std;

int n, m;
multiset<int> tickets;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        tickets.insert(a);
    }
    for (int i = 0, a; i < m; i++) {
        cin >> a;
        auto iter = tickets.upper_bound(a);
        if (iter == tickets.begin()) {
            cout << -1 << '\n';
            continue;
        }

        iter = prev(iter);
        tickets.erase(iter);
        cout << *iter << '\n';
    }
}