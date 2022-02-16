// DMOPC '21 Contest 6 P1 - Bigger Big Integer

#include <bits/stdc++.h>
using namespace std;

int d;
string t;
int main() {
    cin >> d >> t;
    for (int i = 0; i < d - 1; i++) {
        if (t[i] < t[i + 1]) {
            swap(t[i], t[i + 1]);
            break;
        }
    }
    cout << t;
}