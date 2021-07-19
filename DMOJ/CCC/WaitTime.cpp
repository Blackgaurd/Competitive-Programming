// CCC '15 J4 - Wait Time

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = deque<int>;
using qpii = deque<pii>;

//100 people maximum
int m, t=0; // t = time
vi arr[101]; // use vector to store different times messages are sent or received (alternating)
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> m;
    for (int i=0; i<m; i++){ // read input
        char c; cin >> c;
        int n; cin >> n;
        if (c=='R' || c=='S'){arr[n].pb(t); t++;} // R or S mark time in vector
        else t+=n-1; // W means move in time
    }
    for (int i=1; i<=100; i++){ // loop through 100 people
        if (!arr[i].empty()){ // if person has message history
            cout << i << " ";
            if (arr[i].size()%2==1) cout << -1 << nl; // odd num = last mesage was received, not message sent back
            else {
                int sum = 0;
                for (int j=1; j<arr[i].size(); j+=2){
                    sum+=arr[i][j]-arr[i][j-1]; // alternate adding and subtracting
                }
                cout << sum << nl;
            }
        }
    }
    return 0;
}