// Wesley's Anger Contest 6 Problem 1 - Timbit Sales

#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--){
        double p, c; cin >> p >> c;
        p*=100;
        c+=100;
        cout << (p/c) << '\n';
    }

    return 0;
}