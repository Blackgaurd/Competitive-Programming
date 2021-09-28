// Candy Division

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if (n % 2 == 1) {
        cout << 1;
    } else {
        cout << arr[n / 2] - arr[n / 2 - 1];
    }

    return 0;
}