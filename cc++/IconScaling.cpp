// CCC '12 J3 - Icon Scaling

#include <bits/stdc++.h>
using namespace std;

void pr(int x, string ch){
    for (int i=0; i<x; i++) cout << ch;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int k; cin >> k;
    for(int i=0; i<k; i++){
        pr(k,"*");
        pr(k,"x");
        pr(k,"*");
        cout << endl;
    }
    for(int i=0; i<k; i++){
        pr(k," ");
        pr(k,"x");
        pr(k,"x");
        cout << endl;
    }
    for(int i=0; i<k; i++){
        pr(k,"*");
        pr(k," ");
        pr(k,"*");
        cout << endl;
    }
    return 0;
}