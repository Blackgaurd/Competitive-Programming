// Bob's Array Modification

#include<stdio.h>
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, a;
long long pre = 0, ans = 0;
int main(){
    su(n);
    while (n--){
        su(a);
        if (a <= pre){
            ans += pre - a + 1;
            pre++;
        }
        else pre = a;
    }
    printf("%lld\n", ans);
}