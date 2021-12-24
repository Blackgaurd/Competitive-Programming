// USACO 2019 February Bronze P3 - Measuring Traffic

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 103;
int n;
struct {
    char c;
    int l, r;
} arr1[MM], arr2[MM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string t;
        int a, b;
        cin >> t >> a >> b;
        arr1[i] = {t[1], a, b};  // min and max
        arr2[n - i + 1] = {t[1], a, b};
    }
    for (int i = 2; i <= n; i++) {
        if (arr1[i].c == 'n') {
            
        } else if (arr1[i].c == 'o') {
            if (arr1[i - 1].c == 'n') {
                arr1[i].l -= arr1[i - 1].l;
                arr1[i].r -= arr1[i - 1].l;
            } else {
                arr1[i].l = max(arr1[i].l, arr1[i - 1].l);
                arr1[i].r = min(arr1[i].r, arr1[i - 1].r);
            }
        } else { // f
            if (arr1[i - 1].c == 'o') {
                int tmp = arr1[i].l;
                arr1[i].l = arr1[i-1].l - arr1[i].r;
                arr1[i].r = arr1[i-1].r - arr1[i].l;
            } else {
            }
        }
    }
}