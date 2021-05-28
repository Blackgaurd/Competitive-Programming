// InterNAV

#include<bits/stdc++.h>
using namespace std;

int n, m, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char arr[1000][1000];
deque<pair<int, int>> q;
vector<int> vis = {1};
int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
            if (arr[i][j]=='1'){
                q.push_back({i, j});
                arr[i][j] = '#';
            }
        }
    }
    while (!q.empty()){
        auto cur = q.front();
        q.pop_front();
        for (int i=0; i<4; i++){
            if (cur.first+dx[i]>=0 && cur.first+dx[i]<m){
                if (cur.second+dy[i]>=0 && cur.second+dy[i]<n){
                    if (arr[cur.first+dx[i]][cur.second+dy[i]]!='#'){
                        if (arr[cur.first+dx[i]][cur.second+dy[i]]>='2' && arr[cur.first+dx[i]][cur.second+dy[i]]<='9')
                            vis.push_back(arr[cur.first+dx[i]][cur.second+dy[i]] - '0');
                        arr[cur.first+dx[i]][cur.second+dy[i]] = '#';
                        q.push_back({cur.first+dx[i], cur.second+dy[i]});
                    }
                }
            }
        }
    }
    sort(vis.begin(), vis.end());
    for (int i: vis) cout << i << ' ';


    return 0;
}