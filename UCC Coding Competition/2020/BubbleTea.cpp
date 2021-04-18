// UCC Coding Competition '20 P4 - Bubble Tea

#include<bits/stdc++.h>
using namespace std;

const int MM = 1e6+3;
int n, arr[MM], dp[MM];
int two(int a, int b){
    return max(a, b) + (3 * min(a, b)) / 4;
}
int three(int a, int b, int c){
    return a + b + c - min({a, b, c}) / 2;
}
int main(){
    scanf("%d%d%d", &n, &arr[1], &arr[2]);
    dp[1] = arr[1];
    dp[2] = two(arr[1], arr[2]);

    for (int i=3; i<=n; i++){
        scanf("%d", &arr[i]);
        int buytwo = dp[i-2] + two(arr[i], arr[i-1]),
        buythree = dp[i-3] + three(arr[i], arr[i-1], arr[i-2]),
        buyone = dp[i-1] + arr[i];
        dp[i] = min({buyone, buytwo, buythree});
    }

    printf("%d\n", dp[n]);
    return 0;
}