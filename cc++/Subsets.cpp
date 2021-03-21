// CCO '00 P1 - Subsets

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

int n;
unordered_map<char, vector<char>> adj;
unordered_map<char, set<char>> contains;
int to_int(char c) {return c-'A'+1;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<=n; i++){
        string t;
        getline(cin, t);
        adj[t[0]].push_back(t[11]);
    }
    for (char c='A'; c<='Z'; c++){
        if (adj.count(c) && !contains.count(c)){
            deque<char> q = {c};
            bool vis[26];
            while (!q.empty()){
                char cur = q.front();
                q.pop_front();
                vis[to_int(cur)] = true;
                for (auto nxt: adj[cur]){
                    if (nxt>='a'){
                        contains[cur].insert(nxt);
                    } 
                    else {
                        if (contains.count(nxt)){
                            contains[cur].insert(contains[nxt].begin(), contains[nxt].end());
                        }
                        else {
                            q.push_back(nxt);
                        }
                    }
                }
            }
        }
    }
    for (char c='A'; c<='Z'; c++){
        if (adj.count(c)){
            deque<char> q = {c};
            bool vis[26];
            while (!q.empty()){
                char cur = q.front();
                q.pop_front();
                vis[to_int(cur)] = true;
                for (auto nxt: adj[cur]){
                    if (nxt>='a'){
                        contains[cur].insert(nxt);
                    } 
                    else {
                        if (contains.count(nxt)){
                            contains[cur].insert(contains[nxt].begin(), contains[nxt].end());
                        }
                        else {
                            q.push_back(nxt);
                        }
                    }
                }
            }
        }
    }
    for (char c='A'; c<='Z'; c++){
        if (adj.count(c)){
            if (contains.count(c)){
                cout << c << " = ";
                char sep = '{';
                for (auto iter=contains[c].begin(); iter!=contains[c].end(); iter++){
                    cout << sep << *iter;
                    sep = ',';
                }
                cout << "}\n";
            }
            else cout << c << " = {}\n";
        }
    }

    return 0;
}
// too lazy to redo it so run bfs twice
// *work smarter not harder*
