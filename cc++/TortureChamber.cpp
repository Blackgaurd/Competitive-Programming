// The Torture Chamber

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ll long long

ll n, m, cnt = 0;
bool isPrime(int num){
    for (int i=3; i<=sqrt(num); i+=2){
        if (num%i==0) return false;
    }
    return true;
}
int main(){
    cin >> n >> m;

    return 0;
}