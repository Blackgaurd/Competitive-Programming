// COCI '15 Contest 4 #3 Deathstar
// is faster in cpp for some reason

#include<stdio.h>
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int main(){
    int n; su(n);
    for (int i=0; i<n; i++){
        int a = 0;
        for (int j=0, x; j<n; j++){
            su(x);
            a |= x;
        }
        printf("%d ", a);
    }

    return 0;
}