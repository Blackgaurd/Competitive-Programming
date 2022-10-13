// CCC '22 S2 - Good Groups

#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> pss;

int x, y, g;
string a, b, c;
vector<pss> same_group, diff_group;
unordered_map<string, int> group;
int main() {
    cin >> x;
    for (int i = x; i--;) {
        cin >> a >> b;
        same_group.emplace_back(a, b);
    }
    cin >> y;
    for (int i = y; i--;) {
        cin >> a >> b;
        diff_group.emplace_back(a, b);
    }
    cin >> g;
    for (int i = g; i--;) {
        cin >> a >> b >> c;
        group[a] = group[b] = group[c] = i;
    }

    int violations = 0;
    for (auto &[a, b] : same_group) {
        if (group[a] != group[b]) {
            violations++;
        }
    }
    for (auto &[a, b] : diff_group) {
        if (group[a] == group[b]) {
            violations++;
        }
    }

    cout << violations << '\n';
}