// LCC/Moose '20 Contest 3 S5 - Larry and 3

#include<bits/stdc++.h>
using namespace std;

int n, m = 0;
vector<int> adj[101];
bool connected(int start, int end){
    if (adj[start].empty()) return false;
    deque<int> q;
    for (int nxt: adj[start]){
        if (nxt==end) return true;
        q.push_back(nxt);
    }
    while (!q.empty()){
        for (int nxt: adj[q.front()])
            if (nxt==end) return true;
        q.pop_front();
    }
    return false;
}
int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        int out = 0;
        for (int j=1; j<=n; j++){
            if (out<3){
                if (i!=j){
                    bool con1 = connected(i, j);
                    if (!con1){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                        out++;
                    } 
                }
            }
            else break;
        }
    }
    set<set<int>> edges;
    for (int i=1; i<=n; i++){
        for (int con: adj[i]){
            if (!edges.count({i, con})){
                edges.insert({i, con});
                m++;
            }
        }
    }
    cout << m << '\n';
    for (set<int> edge: edges){
        for (int node: edge) cout << node << ' ';
        cout << '\n';
    }

    return 0;
}