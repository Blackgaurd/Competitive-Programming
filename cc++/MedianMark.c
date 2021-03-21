// DMOPC '14 Contest 1 P1 - Median Mark

#include<stdio.h>
#include<math.h>
int n, arr[1001];
int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    if (n&1) printf("%d\n", arr[n/2+1]);
    else {
        float med = arr[n/2] + arr[n/2+1];
        int ans = round(med/2);
        printf("%d\n", ans);
    }
}