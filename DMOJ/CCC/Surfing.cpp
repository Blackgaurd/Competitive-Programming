// CCC '00 S3 - Surfing

#include <bits/stdc++.h>
using namespace std;
#define u_map unordered_map

int n;
u_map<string, vector<string>> adj;
u_map<string, string> p;
u_map<string, u_map<string, bool>> vis;
string flead(string x) {
    if (p[x] != x) p[x] = flead(p[x]);
    return p[x];
}
void dfs(string start, string cur) {
    vis[start][cur] = true;
    for (string nxt : adj[cur]) {
        if (vis[start][nxt] == false) {
            dfs(start, nxt);
        }
    }
}
char _;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    do {
        while ((n = getchar()) < 48)
            ;
        for (n -= 48; 48 <= (_ = getchar()); n = (n << 3) + (n << 1) + _ - 48)
            ;
    } while (0);
    for (int i = 0; i < n; i++) {
        // head website
        string head;
        getline(cin, head);
        while (true) {
            string t;
            getline(cin, t);
            if (!p.count(t)) p[t] = t;
            if (t.length() >= 7) {
                if (t.substr(0, 7) == "</HTML>") break;
                // find 'HREF'
                for (int start = 0; start < t.length() - 3; start++) {
                    if (t.substr(start, 4) == "HREF") {
                        for (int end = 6; end < t.length() - start; end++) {
                            if (t[start + end] == '"') {
                                // cout << "FOUND: " << t.substr(start+6, end-6)
                                // << '\n';
                                adj[head].push_back(
                                    t.substr(start + 6, end - 6));
                                if (flead(head) !=
                                    flead(t.substr(start + 6, end - 6))) {
                                    p[t.substr(start + 6, end - 6)] =
                                        flead(head);
                                }
                                cout << "Link from " << head << " to "
                                     << t.substr(start + 6, end - 6) << '\n';
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    while (true) {
        string a, b;
        getline(cin, a);
        if (a == "The End") break;
        getline(cin, b);
        if (flead(a) == flead(b)) {
            dfs(a, a);
            if (vis[a][b])
                cout << "Can";
            else
                cout << "Can't";
            cout << " surf from " << a << " to " << b << ".\n";
        } else
            cout << "Can't surf from " << a << " to " << b << ".\n";
    }

    return 0;
}