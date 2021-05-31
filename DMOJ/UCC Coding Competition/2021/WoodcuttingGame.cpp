// UCC Coding Competition '21 P5 - Woodcutting Game
// partials

#include<bits/stdc++.h>
using namespace std;

const int MM = 303;
int h1, w1, h2, w2, dp[3][MM][3][MM];
bool solve(int h1, int w1, int h2, int w2){
    int &ret = dp[h1][w1][h2][w2];
    if (ret != -1)
        return ret;
    if (h1 == 1 && w1 == 1 && h2 == 1 && w2 == 1)
        return ret = true;
    ret = false;

    // option 1
    // discard 2
    for (int i = 1; i < w1; i++)
        ret = ret || !solve(h1, i, h1, w1 - i);
    if (h1 == 2)
        ret = ret || !solve(1, w1, 1, w1);

    // discard 1
    for (int i = 1; i < w2; i++)
        ret = ret || !solve(h2, i, h2, w2 - i);
    if (h2 == 2)
        ret = ret || !solve(1, w2, 1, w2);

    // option 2
}
int main(){
    cin >> h1 >> w1 >> h2 >> w2;
    memset(dp, -1, sizeof(dp));

    return 0;
}