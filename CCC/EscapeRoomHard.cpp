// Escape Room (Hard)

#include <bits/stdc++.h>

bool can_escape(int M, int N, std::vector<std::vector<int>> v){
    std::deque<int> q;
    std::vector<int> adj[1000001];
    bool vis[1000001];
    
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            adj[i*j].push_back(v[i][j]);
            if (i==1 && j==1) {q.push_back(v[i][j]); vis[v[i][j]] = true;}
        }
    }
    while (!q.empty()){
        q.pop_front();
        if (q.front()==M*N) {return true;}
        for (auto nxt: adj[q.front()]){
            if (!vis[nxt]){
                vis[nxt] = true;
                q.push_back(nxt);
            }
        }
        q.pop_front();
    }
    return false;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    

    return 0;
}