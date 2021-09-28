// Knapsack 1

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iosync                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

ll N, W, mem[10003];
int main() {
    iosync;
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = W; j >= w; j--) mem[j] = max(mem[j], mem[j - w] + v);
    }
    cout << mem[W] << '\n';

    return 0;
}