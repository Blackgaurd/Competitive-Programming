// Fast Bit Counting

#include<bits/stdc++.h>
using namespace std;

int setbits(unsigned long long x){
    return __builtin_popcountll(x);
}
int main(){
    int a = __builtin_popcount(12);
    cout << a << endl;
}