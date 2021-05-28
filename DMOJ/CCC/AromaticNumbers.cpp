// CCC '12 S2 - Aromatic Numbers

#include<bits/stdc++.h>
using namespace std;

string t;
int _prev = 0, sum = 0;
int val(char c){
    if (c>='0' && c<='9') return c-'0';
    switch (c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}
int main(){
    cin >> t;
    for (int i=t.size()-1; i>=0; i-=2){
        int rom = val(t[i]), num = val(t[i-1]);
        sum+=(rom*num*(rom<_prev?-1:1));
        _prev = rom;
    }
    cout << sum;

    return 0;
}