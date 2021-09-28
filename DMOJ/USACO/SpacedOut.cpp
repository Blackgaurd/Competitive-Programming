// USACO 2021 January Silver P3 - Spaced Out

#include <bits/stdc++.h>
using namespace std;

int n, arr[1003][1003], brr[1003][1003];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            arr[i][j] = brr[j][i] = a;
        }
    }
    int ansv = 0, ansh = 0;
    for (int i = 0; i < n; i++) {
        int oddv = 0, oddh = 0, evenv = 0, evenh = 0;
        for (int j = 0; j < n; j++) {
            if (!(j & 1)) {
                evenv += arr[i][j];
                evenh += brr[i][j];
            } else {
                oddv += arr[i][j];
                oddh += brr[i][j];
            }
        }
        ansv += max(evenv, oddv);
        ansh += max(evenh, oddh);
    }
    cout << max(ansh, ansv) << '\n';

    return 0;
}