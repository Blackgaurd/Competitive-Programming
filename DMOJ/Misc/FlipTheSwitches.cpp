// Flip the Switches

#include<stdio.h>

int n, ans = 0;
bool arr[1000003], cur = 1;
int main(){
    scanf("%d\n", &n);
    for (int i=0; i<n; i++) arr[i] = getchar() - 48;
    for (int i=n-1; i>=0; i--){
        if (arr[i] == cur){
            cur ^= 1;
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}