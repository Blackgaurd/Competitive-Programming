// Miniature Sudoku

#include<bits/stdc++.h>
using namespace std;

int n, arr[5][5];
int sq[] = {0, 1, 1, 3, 3};
vector<pair<int, int>> clear;
bool check(int row_num, int col_num, int val){
    for (int i=1; i<=4; i++){
        if (arr[row_num][i]==val) return false;
    }
    for (int i=1; i<=4; i++){
        if (arr[i][col_num]==val) return false;
    }
    for (int i=sq[row_num]; i<=sq[row_num]+1; i++){
        for (int j=sq[col_num]; j<=sq[col_num]+1; j++){
            if (arr[i][j]==val) return false;
        }
    }
    return true;
}
bool solve(int ind){
    if (ind==clear.size()) return true;
    for (int val = 1; val<=4; val++){
        if (check(clear[ind].first, clear[ind].second, val)){
            arr[clear[ind].first][clear[ind].second] = val;
            if (solve(ind+1)) return true;
            arr[clear[ind].first][clear[ind].second] = 0;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--){
        for (int i=1; i<=4; i++){
            for (int j=1; j<=4; j++){
                char c; cin >> c;
                if (c>='1' && c<='9') arr[i][j] = c-'0';
                else clear.push_back({i, j});
            }
        }

        solve(0);
        for (int i=1; i<=4; i++){
            for (int j=1; j<=4; j++) cout << arr[i][j];
            cout << '\n';
        }
        // this is why u dont name ur vector "clear"
        clear.clear();
    }
    cout << '\n';

    return 0;
}