// IOI '10 P3 - Quality of Living (Standard I/O)

#include <bits/stdc++.h>
using namespace std;

const int MM = 3003;
int r, c, h, w;
vector<vector<int>> arr, psa;
int check(int cur) {
    bool correct = false;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (arr[i][j] < cur)
                psa[i][j] = -1;
            else if (arr[i][j] == cur)
                psa[i][j] = 0;
            else
                psa[i][j] = 1;
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
            if (i >= h && j >= c) {
                int sum = psa[i][j] + psa[i - h][j - w] - psa[i - h][j] - psa[i][j - w];
                if (sum < 0) return -1;        // too big
                if (sum == 0) correct = true;  // correct
            }
        }
    }
    return correct ? 0 : 1;
}
int main() {
    cin >> r >> c >> h >> w;
    arr.assign(r + 1, vector<int>(c + 1));
    psa.assign(r + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> arr[i][j];

    int lo = 1, hi = r * c;
    while (true) {
        int mid = (lo + hi) / 2;
        int median = check(mid);
        if (median == 0) {
            cout << mid << '\n';
            return 0;
        }
        if (median == 1) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
}