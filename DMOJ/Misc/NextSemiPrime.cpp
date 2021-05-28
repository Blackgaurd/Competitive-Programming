// Next Semiprime

#include<bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define nl '\n'

const int MM = 1000;
int q;
bitset<MM> isPrime;
vector<int> semiPrimes;
void genPrimes(){
    isPrime.flip();
    int sq = sqrt(MM);
    for (int i=2; i<=sq; i++){
        if (isPrime[i]){
            for (int j=i*i; j<MM; j+=i) isPrime.reset(j);
        }
    }
}
bool isSemi(int n){
    if (isPrime[n]) return false;
    for (int i=2; i<=sqrt(n); i++){
        if (isPrime[i]){
            if (n%i==0){
                n/=i;
                return isPrime[n];
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    genPrimes();
    cout << isPrime[1];
    /*scan(q);
    while (q--){
        int n; scan(n);
        cout << findNext(n) << nl;
    }*/

    return 0;
}