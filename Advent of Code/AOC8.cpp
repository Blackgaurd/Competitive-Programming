//

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

// 636 lines
bool vis[650], fix = true;
pair<string, int> arr[636];
int acc = 0;

void dfs(int cur){
    if (vis[cur]) return;
    if (cur==635) {cout << "final: " << acc << nl; return;}
    vis[cur] = true;
    if (arr[cur].first=="acc"){
        acc+=arr[cur].second;
        dfs(cur+1);
        acc-=arr[cur].second;
    }
    if (arr[cur].first=="nop"){
        dfs(cur+1);
        if (fix){
            fix = false;
            dfs(cur+arr[cur].second);
            fix = true;
        }
    }
    if (arr[cur].first=="jmp"){
        dfs(cur+arr[cur].second);
        if (fix){
            fix = false;
            dfs(cur+1);
            fix = true;
        }
    }
    vis[cur] = false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    for (int i=0; i<636; i++){
        string a, b;
        cin >> a >> b;
        arr[i] = {a, stoi(b)};
    }
    cout << nl << nl << nl;
    dfs(0);
    qi q; q.pb(0);
    /*while (!q.empty()){
        int cur = q.front();
        q.pop_front();
        vis[cur] = true;
        cout << cur << ": " << arr[cur].first << ", " << arr[cur].second << nl;
        if (arr[cur].first=="acc"){
            acc+=arr[cur].second;
            q.pb(cur+1);
            if (vis[cur+1]) break;
        }
        else if (arr[cur].first=="nop"){
            q.pb(cur+1);
            if (vis[cur+1]) break;
        }
        else if (arr[cur].first=="jmp"){
            q.pb(cur+arr[cur].second);
            if (vis[cur+arr[cur].second]) break;
        }
    }
    cout << acc << nl;
    */

    return 0;
}