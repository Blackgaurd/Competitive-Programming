// UCC Coding Competition '21 P5 - Woodcutting Game
// partials

#include<bits/stdc++.h>
using namespace std;

int h1, w1, h2, w2;
bool win = false;
int main(){
    cin >> h1 >> w1 >> h2 >> w2;
    if (w1 == 1 || w2 == 1){
        if (w1 + w2 == 2) win = true;
    }
    else if (w1 == 2 || w2 == 2) win = true;

    return 0;
}