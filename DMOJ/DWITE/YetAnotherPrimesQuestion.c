// DWITE '07 R3 #1 - Yet Another Primes Question

#include<stdio.h>
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int main(){
    int prime[501], primes[95], ind = 1;
    primes[0] = 2;
    for (int i=2; i<=500; i++) prime[i] = 1;
    for (int i=4; i<=500; i+=2) prime[i] = 0;
    for (int i=3; i<=500; i+=2){
        if (prime[i]){
            for (int j=i*2; j<=500; j+=i)
                prime[j] = 0;
            primes[ind] = i;
            ind++;
        }
    }
    for (int e=5; e; e--){
        int a, fac = 0; su(a);
        for (int i=0; i<95; i++){
            if (a%primes[i] == 0){
                fac++;
                while (a%primes[i] == 0)
                    a /= primes[i];
            }
        }
        if (fac == 3) printf("valid\n");
        else printf("not\n");
    }

    return 0;
}