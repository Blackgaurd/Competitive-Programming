// COCI '06 Contest 1 #4 Slikar

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define nl '\n'

int r, c, finx, finy, dis[50][50], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char arr[50][50];
bool vis[50][50];
deque<pair<int, int>> w, b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            char c; cin >> c;
            arr[i][j] = c;
            if (c=='.') continue;
            if (c=='*') w.pb(mp(i, j));
            else if (c=='S') b.pb(mp(i, j));
            else if (c=='D'){
                finx = i; finy = j;
            }
        }
    }
    // '*' = visited   
    while (!b.empty()){
        int wlen = w.size();
        while (wlen--){
            int curx = w.front().first, cury = w.front().second;
            //cout << curx << " " << cury << nl;
            for (int i=0; i<4; i++){
                if (curx+dx[i]>=0 && curx+dx[i]<r){
                    if (cury+dy[i]>=0 && cury+dy[i]<c){
                        if (arr[curx+dx[i]][cury+dy[i]]=='.'){
                            arr[curx+dx[i]][cury+dy[i]] = '*';
                            w.pb(mp(curx+dx[i], cury+dy[i]));
                        }
                    }
                }
            }
            w.pop_front();
        }
        int curx = b.front().first, cury = b.front().second;
        for (int i=0; i<4; i++){
            if (curx+dx[i]>=0 && curx+dx[i]<r){
                if (cury+dy[i]>=0 && cury+dy[i]<c){
                    if (arr[curx+dx[i]][cury+dy[i]]!='*' && arr[curx+dx[i]][cury+dy[i]]!='X'){
                        dis[curx+dx[i]][cury+dy[i]] = dis[curx][cury]+1;
                        arr[curx+dx[i]][cury+dy[i]] = '*';
                        b.pb(mp(curx+dx[i], cury+dy[i]));
                    }
                }
            }
        }
        /*
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++) cout << arr[i][j];
            cout << nl;
        }
        cout << nl;
        */
        b.pop_front();
    }
    if (dis[finx][finy]) cout << dis[finx][finy] << nl;
    else cout << "KAKTUS\n";
    

    return 0;
}