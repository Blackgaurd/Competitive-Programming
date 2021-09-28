// Another Contest 7 Problem 2 - Code Review

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
void scramble() {
    vector<int> ret;
    for (int l = n; l >= 1; l--) {
        int ind = rand() % l;
        swap(arr[l - 1], arr[ind]);
        ret.push_back(arr.back());
        arr.pop_back();
    }
    arr = ret;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) arr.push_back(i);
    while (true) {
        scramble();
        for (int i : arr) printf("%d ", i);
        printf("\n");
        fflush(stdout);

        int in;
        scanf("%d", &in);
        if (!in) break;
    }

    return 0;
}