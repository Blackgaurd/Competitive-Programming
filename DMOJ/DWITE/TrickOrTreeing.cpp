// DWITE '12 R1 #4 - Trick or Tree'ing

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define nl "\n"

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    for (int k=0; k<5; k++){
        int dis = 0, c = 0, b = 0, vertices = 0;
        string t; getline(cin, t);
        for (int i=0; i<t.size(); i++){
            if (t[i]=='(') {b++; dis = max(dis, b); vertices++;}
            else if (t[i]==')') b--;
            string tmp = "";
            while (isdigit(t[i])){tmp+=t[i]; i++;}
            if (tmp.size()!=0) {c+=stoi(tmp); vertices++; i--;}
        }
        // 2 * total edges - longest path from root
        cout << 2*(vertices-1)-dis << " " << c << nl;
    }

    return 0;
}