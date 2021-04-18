// CCO '05 P4 - Primed Sequences

#include<bits/stdc++.h>
using namespace std;
#ifndef WIN32
#define getchar getchar_unlocked
#endif
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
typedef long long ull;

ull mul_mod(ull a, ull b, ull m) {
    if (m == 0) return a * b;
    ull r = 0;
    while (a > 0) {
        if (a & 1) if((r += b) > m) r %=m;
        a >>= 1;
        if ((b <<= 1) > m) b %= m;
    }
    return r;
}

ull qpow(ull a, ull n, ull m) {
    ull r = 1;
    while (n > 0) {
        if (n & 1) r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
        n >>= 1;
    }
    return r;
}

bool checkComposite(ull n, ull a, ull d, int p){
    ull x = qpow(a, d, n);
    if (x==1 || x==n-1) return false;
    for (int i=1; i<p; i++){
        x = mul_mod(x, x, n);
        if (x==n-1) return false;
    }
    return true;
}

bool isPrime(ull n) {
    if (n <= 4) return n == 2 || n == 3;
    if (!(n&1)) return false;
    int r = 0;
    ull d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 13, 29, 31, 37}) {
        if (n == a) return 1;
        if (checkComposite(n, a, d, r)) return 0;
    }
    return true;
}

bool trialDiv(int n){
    if (n<=2) return n == 2;
    if (!(n&1)) return false;
    for (int i=3; i<=sqrt(n); i+=2){
        if (!(n%i)) return false;
    }
    return true;
}

const int MM = 1e4+3;
int t, psa[MM], arr[MM];
int main(){
    su(t);
    while (t--){
        int n; su(n);
        for (int i=1; i<=n; i++){
            su(arr[i]);
            psa[i] = arr[i] + psa[i-1];
        }

        bool flag = false;
        for (int len=2; len<=n; len++){
            for (int i=1; i+len<=n+1; i++){
                int j = i + len - 1;
                int sum = psa[j] - psa[i-1];

                if (isPrime(sum)){
                    printf("Shortest primed subsequence is length %d:", len);
                    for (int ind=i; ind<=j; ind++) printf(" %d", arr[ind]);
                    putchar('\n');
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) printf("This sequence is anti-primed.\n");
    }

    return 0;
}