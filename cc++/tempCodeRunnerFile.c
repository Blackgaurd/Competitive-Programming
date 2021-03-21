#include<stdio.h>

#define ll long long
int main(){
    int n, p, m;
    scanf("%d%d%d", &n, &p, &m);
    ll ans = 1;
    while (p){
        if (p&1){
            ans*=n;
            ans%=m;
        }
        n*=n;
        n%=m;
        p>>=1;
    }
    printf("%lld", ans);

    return 0;
}