// XOR

#include<bits/stdc++.h>
using namespace std;

int XOR(int n){
    int mod = n%4;
    if (mod==0) return n;
    if (mod==1) return 1;
    if (mod==2) return n+1;
    if (mod==3) return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    while (n--){
        int a, b; cin >> a >> b;
        cout << (XOR(a-1)^XOR(b)) << '\n';
    }

    return 0;
}