// Mock CCC '18 Contest 3 S4 - A Graph Problem

#include<bits/stdc++.h>
using namespace std;
int n, sum = 0, big = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--){
        int a; cin >> a;
        sum+=a;
        big = max(big, a);
    }
    cout << (sum-big>=big?"YES":"NO") << '\n';

    return 0;
}