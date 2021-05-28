// Distinct Prime Factors

#include<bits/stdc++.h>
using namespace std;

int a, b;
int fac(int x){
    int ret = 0;
    if (!(x&1)) ret++;
    while (!(x&1)) x >>= 1;
    for (int i=3; i<=sqrt(x); i++){
        if (x % i == 0){
            while (x % i == 0) x /= i;
            ret++;
        }
    }
    if (x != 1) ret++;
    return ret;
}
int main(){
    scanf("%d%d", &a, &b);
    // naive solution
    for (int i=a; i<=b; i++){
        printf("%d\n", fac(i));
    }

    return 0;
}