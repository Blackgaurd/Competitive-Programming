// Next Prime (Hard)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

const int confidence = 4;
const int MM = 600000;
ull n;
bool prime[MM+1];
vector<int> p;

ull mul_mod(ull a, ull b, ull m) {
    if (m == 0) return a * b;
    ull r = 0;
    while (a > 0) {
        if (a & 1)
            if((r += b) > m) r %=m;
        a >>= 1;
        if ((b <<= 1) > m) b %= m;
    }
    return r;
}

ull qpow(ull a, ull n, ull m) {
    ull r = 1;
    while (n > 0) {
        if (n & 1)
            r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
        n >>= 1;
    }
    return r;
}

ull gcd(ull a, ull b){
    if (!a) return b;
    return gcd(b%a, a);
}

// for speed purposes, only works with odd numbers
bool isprime(ull n){
    ull tmp = sqrt(n);
    for (auto i: p){
        if (i<=tmp){
            if (n%i==0 && n/i!=1) return false;
        }
        else break;
    }
    for (int k=0; k<confidence; k++){
        ull r = rand()%(n-4)+2;
        if (qpow(r, n-1, n)!=1) return false;
    }
    return true;
}

bool trialDiv(int n){
    for (int i=3; i<=sqrt(n); i+=2){
        if (n%i==0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    if (n<=2){
        cout << 2 << '\n';
        return 0;
    }
    if (!(n&1)) n++;
    if (n==3 || n==5){
        cout << n << '\n';
        return 0;
    }
    p.push_back(2);
    for (int i=3; i<=MM; i+=2){
        if (trialDiv(i)) p.push_back(i);
    }
    while (true){
        if (!isprime(n)) n+=2;
        else {
            cout << n << '\n';
            break;
        }
    }
    
    return 0;
}