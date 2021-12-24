// Weird Algorithm

#include<cstdio>

long long n;
int main(){
    scanf("%lld", &n);
    while (n != 1){
        printf("%lld ", n);
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
    }
    printf("1\n");
}