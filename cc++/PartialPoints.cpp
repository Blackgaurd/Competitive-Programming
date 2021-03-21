//

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

const int MM = 1e4+5;
int n, arr[MM][MM], sols[51];
pair<int, int> pos[51];
char dir[51];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> dir[i];
        int x, y; cin >> x >> y;
        arr[x][y] = 1;
        pos[i] = {x, y};
    }
    fill(sols+1, sols+n+1, -1);
    deque<int> q;
    for (int i=1; i<=n; i++) q.push_back(i);
    while (!q.empty()){
        int i = q.front();
        //cout << pos[i].first << " " << pos[i].second << '\n';
        if (dir[i]=='N'){
            if (arr[pos[i].first][pos[i].second+1]==0 || arr[pos[i].first][pos[i].second+1]==arr[pos[i].first][pos[i].second]+1){
                arr[pos[i].first][pos[i].second+1] = arr[pos[i].first][pos[i].second]+1;
                pos[i].second++;
                q.push_back(i);
            }
            else{
                sols[i] = arr[pos[i].first][pos[i].second];
                dir[i] = '.';
            }
        }
        else if (dir[i]=='E'){
            if (arr[pos[i].first+1][pos[i].second]==0 || arr[pos[i].first+1][pos[i].second]==arr[pos[i].first][pos[i].second]+1){
                arr[pos[i].first+1][pos[i].second] = arr[pos[i].first][pos[i].second]+1;
                pos[i].first++;
                q.push_back(i);
            }
            else{
                sols[i] = arr[pos[i].first][pos[i].second];
                dir[i] = '.';
            }
        }
        if (pos[i].first>MM || pos[i].second>MM){
            dir[i] = '.';
            sols[i] = -1;
        }
        q.pop_front();
    }
    for (int i=1; i<=n; i++){
        if (sols[i]==-1 || sols[i]>=MM) cout << "Infinity\n";
        else cout << sols[i] << '\n';
    }
    /*for (int i=1; i<=100; i++){
        for (int j=1; j<=100; j++) cout << arr[i][j] << " ";
        cout << '\n';
    }*/

    return 0;
}