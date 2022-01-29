// An Animal Contest 5 P2 - Permutations & Products

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> p, arr;
ll check(int i, int j) {
    printf("? %d %d\n", i, j);
    fflush(stdout);
    ll ret;
    scanf("%lld", &ret);
    return ret;
}
int main() {
    scanf("%d", &n);
    arr.resize(n + 1);
    p.resize(n + 1);
    ll mx = -1, mx_ind = 0;
    ll mn = LLONG_MAX, mn_ind = 0;
    for (int i = 2; i <= n; i++) {
        p[i] = check(1, i);
        if (p[i] > mx) {
            mx = p[i];
            mx_ind = i;
        }
        if (p[i] < mn) {
            mn = p[i];
            mn_ind = i;
        }
    }
    if (p[mx_ind] == n) {
        arr[1] = 1;
    } else {
        arr[1] = p[mn_ind];
    }
    for (int i = 2; i <= n; i++) {
        arr[i] = p[i] / arr[1];
    }
    printf("!");
    for (int i = 1; i <= n; i++) printf(" %d", arr[i]);
    printf("\n");
}