// Catch the Cat

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

const int MM = 1000000;
int x, y, dis[MM] = {0};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> x >> y;
    if (y<=x) {cout << x-y; return 0;}
    dis[x] = 1;
    qi q; q.pb(x);
    while (!q.empty()){
        int cur = q.front(); q.pop_front();
        if (cur/2>y) continue;
        if (cur==y) {cout << dis[cur]-1 << nl; break;}
        //cout << cur << " dis: " << dis[cur]-1 << nl;
        if (cur+1<=MM && dis[cur+1]==0){
            dis[cur+1] = dis[cur]+1;
            q.pb(cur+1);
        }
        if (cur-1>=0 && dis[cur-1]==0){
            dis[cur-1] = dis[cur]+1;
            q.pb(cur-1);
        }
        if (cur*2<=MM && dis[cur*2]==0){
            dis[cur*2] = dis[cur]+1;
            q.pb(cur*2);
        }
    }

    return 0;
}