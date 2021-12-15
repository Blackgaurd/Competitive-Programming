// Another Contest 4 Problem 6 - One Billion Views

#include <bits/stdc++.h>
using namespace std;

int nxt(int n) {
    int ret = 0;
    while (n) {
        int cur = n % 10;
        ret += cur * cur;
        n /= 10;
    }
    return ret;
}
bool f(int n) {
    unordered_set<int> seen;
    while (true) {
        if (!seen.empty() && seen.find(n) != seen.end()) return false;
        if (n == 1) return true;
        seen.insert(n);
        n = nxt(n);
    }
}
int main() {}