// Mock CCC '20 Contest 1 J3 - A Geometry Problem

#include<bits/stdc++.h>
using namespace std;

int x, y;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x >> y;
    cout << x*y/4;
    switch(x*y%4){
        case 0: 
            cout << ".00\n";
            break;
        case 1: 
            cout << ".25\n";
            break;
        case 2: 
            cout << ".50\n";
            break;
        case 3: 
            cout << ".75\n";
            break;
    }
}
