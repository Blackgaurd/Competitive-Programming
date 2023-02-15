#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 100;
    int sum_square = 0, square_sum = 0;
    for (int i = 1; i <= n; i++) {
        sum_square += i;
        square_sum += i * i;
    }
    printf("%d\n", sum_square * sum_square - square_sum);
}