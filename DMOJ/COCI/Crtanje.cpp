// COCI '20 Contest 2 #1 Crtanje

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#define scan(x)                                                                   \
    do {                                                                          \
        while ((x = getchar()) < '0')                                             \
            ;                                                                     \
        for (x -= '0'; '0' <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - '0') \
            ;                                                                     \
    } while (0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

int n, hi = 1000, lo = 1000, x = 1000;
string t;
char arr[2005][1005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> t;
    if (t[0] == '-')
        arr[x][0] = '\\';
    else if (t[0] == '+')
        arr[x][0] = '/';
    else
        arr[x][0] = '_';
    for (int i = 1; i < n; i++) {
        if (t[i - 1] == '-' && t[i] == '-') {
            x++;
            lo = max(lo, x);
        } else if (t[i - 1] == '+') {
            if (t[i] == '+') {
                x--;
                hi = min(hi, x);
            } else if (t[i] == '=') {
                x--;
                hi = min(hi, x);
            }
        } else if (t[i - 1] == '=' && t[i] == '-') {
            x++;
            lo = max(lo, x);
        }
        if (t[i] == '-')
            arr[x][i] = '\\';
        else if (t[i] == '+')
            arr[x][i] = '/';
        else
            arr[x][i] = '_';
    }
    for (int i = hi; i <= lo; i++) {
        for (int j = 0; j < n; j++) cout << (arr[i][j] ? arr[i][j] : '.');
        cout << nl;
    }

    return 0;
}