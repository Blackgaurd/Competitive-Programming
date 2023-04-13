#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const regex pattern("^1\\d2\\d3\\d4\\d5\\d6\\d7\\d8\\d9\\d0$");
bool check(ull x) {
    string x_str = to_string(x);
    return regex_match(x_str, pattern);
}
int main() {
    ull mn = sqrt(1020304050607080900);
    ull mx = sqrt(1929394959697989990);

    for (ull x = mn; x <= mx; x += 10) {
        if (check(x * x)) {
            printf("%llu\n", x);
            break;
        }
    }
}