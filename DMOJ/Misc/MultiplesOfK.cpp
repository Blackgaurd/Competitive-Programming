// Multiple of K

#include<bits/stdc++.h>
using namespace std;
#define su(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;

const int MM = 1e6+5;
int n, k;
ll arr[MM];
int main(){
    su(n); su(k);
    for (int i=1; i<=n; i++){
        su(arr[i]);
        arr[i] %= k;
        arr[i] += arr[i-1];
    }

    for (int len=n; len>=1; len--){
        for (int i=1; i+len<=n; i++){
            // printf("%d - %d : %d\n", i, i+len, arr[i+len]-arr[i-1]);
            if ((arr[i+len] - arr[i-1])%k == 0){
                printf("%d\n", len + 1);
                return 0;
            }
        }
    }
    printf("-1\n");

    return 0;
}