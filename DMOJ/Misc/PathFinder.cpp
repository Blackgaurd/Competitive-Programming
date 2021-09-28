// Path Finder

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define scan(x)                                 \
    do {                                        \
        while ((x = getchar()) < '0')           \
            ;                                   \
        for (x -= '0'; '0' <= (_ = getchar());  \
             x = (x << 3) + (x << 1) + _ - '0') \
            ;                                   \
    } while (0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

// see if blocked tiles draw a line from one edge to another
// two connected edges can not be top+right or bottom+left
int n, m, k;
set<pii> blocked;
deque<pii> q;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        blocked.insert(mp(a, b));
    }

    return 0;
}