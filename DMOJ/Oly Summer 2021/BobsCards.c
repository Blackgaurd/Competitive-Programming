// Bob's Cards

#include<stdio.h>
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, a, cur = 1;
int main(){
    su(n);
    for (int i=0; i<n; i++){
        su(a);
        if (a == cur) cur++;
    }
    printf("%d\n", cur == 1 ? -1 : n - cur + 1);
}