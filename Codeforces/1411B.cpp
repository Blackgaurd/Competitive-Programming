// B. Fair Numbers

#include<stdio.h>
typedef long long ll;
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int t;
ll n;
bool check(ll x){
    bool div[10];
    for (int i=0; i<10; i++) div[i] = true;
    if (x & 1) div[2] = div[4] = div[6] = div[8] = false;
    if (div[4]) div[4] = !(x&3);
    if (div[8]) div[8] = !(x&7);
    if (x % 3) div[3] = div[6] = div[9] = false;
    if (div[9]) div[9] = (x % 9 == 0);
    if (x % 5) div[5] = false;
    if (x % 7) div[7] = false;

    do { if (!div[x%10]) return false; }
    while (x /= 10);
    return true;
}
int main(){
    su(t);
    while (t--){
        su(n);
        while (!check(n)) n++;
        printf("%lld\n", n);
    }

    return 0;
}
