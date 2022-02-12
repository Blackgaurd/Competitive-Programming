// 2-Dimensional Range Minimum Query
// using sparse table

#include <bits/stdc++.h>
using namespace std;

const int MM = 1000, LOGM = 10;
int sparse[LOGM][LOGM][MM][MM], qlog2[MM + 3];
void init(vector<vector<int>> arr) {
    int n = arr.size();
    qlog2[1] = 0;
    for (int i = 2; i <= n; i++) {
        qlog2[i] = qlog2[i / 2] + 1;
    }
    for (int i = 0; (1 << i) <= n; i++) {
        for (int j = 0; (1 << j) <= n; j++) {
            for (int x = 0; x + (1 << i) - 1 < n; x++) {
                for (int y = 0; y + (1 << j) - 1 < n; y++) {
                    if (i == 0 && j == 0) {
                        sparse[i][j][x][y] = arr[x][y];
                    } else if (i == 0) {
                        sparse[i][j][x][y] =
                            min(sparse[i][j - 1][x][y],
                                sparse[i][j - 1][x][y + (1 << (j - 1))]);
                    } else if (j == 0) {
                        sparse[i][j][x][y] =
                            min(sparse[i - 1][j][x][y],
                                sparse[i - 1][j][x + (1 << (i - 1))][y]);
                    } else {
                        sparse[i][j][x][y] =
                            min({sparse[i - 1][j - 1][x][y],
                                 sparse[i - 1][j - 1][x + (1 << (i - 1))][y],
                                 sparse[i - 1][j - 1][x][y + (1 << (j - 1))],
                                 sparse[i - 1][j - 1][x + (1 << (i - 1))]
                                       [y + (1 << (j - 1))]});
                    }
                }
            }
        }
    }
}
int query(int a, int b, int c, int d) {
    int x = a, y = c, x1 = b, y1 = d;
    int k = qlog2[x1 - x + 1], l = qlog2[y1 - y + 1];
    int ans = min({sparse[k][l][x][y], sparse[k][l][x1 - (1 << k) + 1][y],
                   sparse[k][l][x][y1 - (1 << l) + 1],
                   sparse[k][l][x1 - (1 << k) + 1][y1 - (1 << l) + 1]});
    return ans;
}
int main() { return 0; }