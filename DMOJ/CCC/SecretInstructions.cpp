#include<bits/stdc++.h>
using namespace std;

bool _right = false;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (true){
        string t; cin >> t;
        if (t == "99999") break;
        int dir = t[0] + t[1] - '0' - '0';
        if (dir){
            if (dir&1) _right = false;
            else _right = true;
        }
        cout << (_right? "right ":"left ") << t.substr(2, 3) << '\n';
    }
    return 0;
}