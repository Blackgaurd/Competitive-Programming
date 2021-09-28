// CCC '12 S5 - Mouse Journey

#include <iostream>
using namespace std;

int r, c, k, paths[26][26];
void dfs(int x, int y) {
    if (paths[x + 1][y] == 0 && x + 1 <= r) {
        dfs(x + 1, y);
    }
    if (paths[x][y + 1] == 0 && y + 1 <= c) {
        dfs(x, y + 1);
    }
    if (paths[x + 1][y] != -1) paths[x][y] += paths[x + 1][y];
    if (paths[x][y + 1] != -1) paths[x][y] += paths[x][y + 1];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        paths[a][b] = -1;
    }
    paths[r][c] = 1;
    dfs(1, 1);
    cout << paths[1][1] << '\n';

    return 0;
}