// SAC '22 Code Challenge 4 P2 - Obligatory String Problem

#include <bits/stdc++.h>
using namespace std;

int k;
string a, b;
int main() {
    cin >> k >> a;
    b.resize(4);
    for (b[0] = 'a'; b[0] <= 'z'; b[0]++) {
        for (b[1] = 'a'; b[1] <= 'z'; b[1]++) {
            for (b[2] = 'a'; b[2] <= 'z'; b[2]++) {
                for (b[3] = 'a'; b[3] <= 'z'; b[3]++) {
                    int dis = 0;
                    for (int i = 0; i < 4; i++) {
                        dis += min(abs(a[i] - b[i]), a[i] - b[i] - 'a' + 'z' + 1);
                    }
                    if (dis <= k) {
                        cout << b << '\n';
                    }
                }
            }
        }
    }
}