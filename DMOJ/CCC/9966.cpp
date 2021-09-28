// CCC '00 J2 - 9966

#include <bits/stdc++.h>
using namespace std;

bool arr[32005];
void gen(int x) {
    if (x > 32000) return;
    arr[x] = true;
    int len;
    if (x < 10)
        len = 100;
    else if (x < 100)
        len = 1000;
    else if (x < 1000)
        len = 10000;
    else if (x < 10000)
        len = 100000;
    else
        len = 1000000;
    gen(6 * len + 10 * x + 9);
    gen(9 * len + 10 * x + 6);
    gen(1 * len + 10 * x + 1);
    gen(8 * len + 10 * x + 8);
    len *= 100;
    gen(6 * len + 100 * x + 9);
    gen(9 * len + 100 * x + 6);
    gen(1 * len + 100 * x + 1);
    gen(8 * len + 100 * x + 8);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    gen(1);
    gen(8);
    gen(69);
    gen(96);
    gen(11);
    gen(88);
    gen(101);
    gen(609);
    gen(906);
    gen(808);
    gen(1001);
    gen(6009);
    gen(9006);
    gen(8008);
    gen(10001);
    int a, b, count = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (arr[i]) count++;
    }
    cout << count;

    return 0;
}