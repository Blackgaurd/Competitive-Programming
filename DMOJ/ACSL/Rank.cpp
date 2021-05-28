// Rank

#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> adj[21];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i=0, a, b, sa, sb; i<k; i++){
        cin >> a >> b >> sa >> sb;
        if (sa > sb) adj[a].emplace_back(b);
        else adj[b].emplace_back(a);
    }

    return 0;
}