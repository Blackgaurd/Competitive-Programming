// BSSPC '21 J2 - James and YouTube

#include <bits/stdc++.h>
using namespace std;

int n, m;
bool arr[1443];
int main() {
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        for (int i = a; i <= b; i++) arr[i] = true;
    }
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        bool flag = true;
        for (int i = a; i <= b; i++) {
            if (arr[i]) {
                printf(
                    "Break is Over! Stop playing games! Stop watching "
                    "Youtube!\n");
                flag = false;
                break;
            }
        }
        if (flag) printf(":eyy:\n");
    }
}