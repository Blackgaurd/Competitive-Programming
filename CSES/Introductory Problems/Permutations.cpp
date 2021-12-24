// Permutations

#include <cstdio>
#include <deque>

int n;
std::deque<int> arr;
int main() {
    scanf("%d", &n);
    if (n == 2 || n == 3){
        printf("NO SOLUTION\n");
        return 0;
    }
    arr.push_back(n);
    for (int i = 1; i < n; i++) {
        if (i & 1)
            arr.push_front(i);
        else
            arr.push_back(i);
    }
    for (int i : arr) printf("%d ", i);
}