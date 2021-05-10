// DMOPC '14 Contest 6 P2 - Longest Tunnel

#include<stdio.h>
#define max(a, b) (a>b? a:b)

int n, ans = 0;
int main(){
    scanf("%d", &n);
    while (n--){
        int a, b; scanf("%d%d", &a, &b);
        ans = max(ans, b - a);
    }
    printf("%d\n", ans);
    return 0;
}