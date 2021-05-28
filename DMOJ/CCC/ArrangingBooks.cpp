// CCC '21 J4 - Arranging Books

#include<bits/stdc++.h>
using namespace std;

string t, cop;
int main(){
    cin >> t;
    cop = t;
    sort(cop.begin(), cop.end());

    // swap L and S
    int i = 0, MinL = 0, LinM = 0, NonS = 0;
    for (; i<t.size() && cop[i] == 'L'; i++){
        if (t[i] == 'M') MinL++;
    }
    for (; i<t.size() && cop[i] == 'M'; i++){
        if (t[i] == 'L') LinM++;
    }
    for (; i<t.size(); i++){
        if (t[i] != 'S') NonS++;
    }

    int ans = max(MinL, LinM) + NonS;
    cout << ans << '\n';
}