#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 1e5 + 3;
bool p[MM];
pii rads[MM];
int main() {
    memset(p, true, sizeof(p));
    for (int i = 1; i < MM; i++) rads[i] = {1, i};
    for (int i = 2; i < MM; i++) {
        if (!p[i]) continue;
        rads[i].first = i;
        for (int j = i + i; j < MM; j += i) {
            p[j] = false;
            rads[j].first *= i;
        }
    }

    sort(rads + 1, rads + MM - 1);
    printf("%d\n", rads[10000].second);
}