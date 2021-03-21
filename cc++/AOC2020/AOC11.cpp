#include<bits/stdc++.h>
using namespace std;
#define nl "\n"

// 90 wide, 91 tall
const int W = 90, T = 91;
char room[93][92], nxt[93][92];
int rounds = 0, dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {1, 0, -1, -1, -1, 0, 1, 1};
bool change = true;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    for (int i=1; i<=T; i++){
        for (int j=1; j<=W; j++){
            cin >> nxt[i][j];
        }
    }
    while (true){
        cout << "1: " << change << nl;
        if (change){
            change = false;
            // copy array
            for (int i=1; i<=T; i++){
                for (int j=1; j<=W; j++){
                    room[i][j] = nxt[i][j];
                }
            }
            // loop
            for (int i=1; i<=T; i++){
                for (int j=1; j<=W; j++){
                    if (room[i][j]=='L'){
                        bool flag = false;
                        for (int dir=0; dir<8; dir++){
                            /* part 1
                            if (room[i+dx[dir]][j+dy[dir]]=='#') 
                                flag = true;
                            */
                            int prevx = i, prevy = j;
                            while (true){
                                prevx+=dx[dir]; prevy+=dy[dir];
                                if (prevx>=1 && prevx<=T && prevy>=1 && prevy<=W){
                                    if (room[prevx][prevy]=='#'){
                                        flag = true;
                                        break;
                                    }
                                    else if (room[prevx][prevy]=='L') break;
                                } else break;
                            }
                        }
                        if (!flag){
                            nxt[i][j] = '#';
                            change = true;
                        }
                    }
                }
            }
        } else break;
        cout << "2: " << change << nl;
        if (change){
            change = false;
            // copy array
            for (int i=1; i<=T; i++){
                for (int j=1; j<=W; j++){
                    room[i][j] = nxt[i][j];
                }
            }
            // loop
            for (int i=1; i<=T; i++){
                for (int j=1; j<=W; j++){
                    if (room[i][j]=='#'){
                        int occupied = 0;
                        for (int dir=0; dir<8; dir++){
                            /* part 1
                            if (room[i+dx[dir]][j+dy[dir]]=='#') 
                                occupied++;
                            */
                        
                        int prevx = i, prevy = j;
                            while (true){
                                prevx+=dx[dir]; prevy+=dy[dir];
                                if (prevx>=1 && prevx<=T && prevy>=1 && prevy<=W){
                                    if (room[prevx][prevy]=='#'){
                                        occupied++;
                                        break;
                                    }
                                    else if (room[prevx][prevy]=='L') break;
                                } else break;
                            }
                        }
                        if (occupied>=5){
                            nxt[i][j] = 'L';
                            change = true;
                        }
                    }
                }
            }
        } else break;

    }
    int seats = 0;
    for (int i=1; i<=T; i++){
        for (int j=1; j<=W; j++){
            if (nxt[i][j]=='#') seats++;
            cout << nxt[i][j];
        }
        cout << nl;
    }
    cout << seats << nl;

    return 0;
}