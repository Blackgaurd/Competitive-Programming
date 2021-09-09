// CPC '21 Contest 1 P0 - AQT and Alphabet

#include<bits/stdc++.h>
using namespace std;

string t;
int main(){
    cin >> t;
    for (char c='a'; c<='z'; c++){
        if (t.find(c) >= t.size()){
            cout << c << '\n';
            return 0;
        }
    }

    return 0;
}