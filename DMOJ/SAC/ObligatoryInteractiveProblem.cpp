// SAC '22 Code Challenge 4 P5 - Obligatory Interactive Problem

#include <bits/stdc++.h>
using namespace std;

int n, q1, q2, t;
vector<int> arr;
vector<bool> found;
bool cmp(int a, int b) {
    printf("c %d %d\n", a, b);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret == b;
}
int main() {
    scanf("%d%d%d%d", &n, &q1, &q2, &t);
    arr.resize(n + 1);
    found.resize(n + 1);
    for (int i = max(n - q2 + 1, 1); i <= n; i++) {
        printf("h %d\n", i);
        fflush(stdout);
        scanf("%d", &arr[i]);
        found[arr[i]] = true;
    }
    if (q2 < n) {
        vector<int> rest(n - q2);
        for (int i = 0; i < rest.size(); i++) {
            rest[i] = i + 1;
        }
        sort(rest.begin(), rest.end(), cmp);
        int x = 1;
        for (int i : rest) {
            while (found[x]) x++;
            arr[i] = x++;
        }
    }
    printf("!");
    for (int i = 1; i <= n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
