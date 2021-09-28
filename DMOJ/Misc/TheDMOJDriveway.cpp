// The DMOJ Driveway

#include <bits/stdc++.h>
using namespace std;

int t, m;
string x, c;
deque<string> q;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (cin >> t >> m; t--;) {
        cin >> x >> c;
        if (c.back() == 'n')
            q.push_back(x);
        else if (m && q.front() == x) {
            m--;
            q.pop_front();
        } else if (q.back() == x)
            q.pop_back();
    }
    for (string s : q) cout << s << '\n';

    return 0;
}