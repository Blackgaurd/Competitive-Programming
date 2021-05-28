// DMPG '17 S2 - Anime Conventions

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define nl "\n"

const int MM = 1e5+5;
int n, q, arr[MM];
int find_leader(int x){
    if (arr[x]!=x){
        arr[x] = find_leader(arr[x]);
    }
    return arr[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    cin >> n >> q;
    // initiate disjoint set
    for (int i=1; i<=n; i++){
        arr[i] = i;
    }
    for (int k=0; k<q; k++){
        char c; int a, b;
        cin >> c >> a >> b;
        int fa = find_leader(a), fb = find_leader(b);
        if (c=='A'){
            // union sets a and b
            arr[fa] = fb;
        }
        else if (c=='Q'){
            // do a and b have the same leader?
            cout << (fa==fb? "Y":"N") << nl;
        }
    }

    return 0;
}