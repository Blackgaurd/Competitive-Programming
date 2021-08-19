// Sudoku Challenge

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

char arr[10][10];
int sq[] = {0, 1, 1, 1, 4, 4, 4, 7, 7, 7};
vector<pair<int, int>> clear;
bool check(int row_num, int col_num, char val){
    for (int i=1; i<=9; i++){
        if (arr[row_num][i]==val) return false;
    }
    for (int i=1; i<=9; i++){
        if (arr[i][col_num]==val) return false;
    }
    for (int i=sq[row_num]; i<=sq[row_num]+2; i++){
        for (int j=sq[col_num]; j<=sq[col_num]+2; j++){
            if (arr[i][j]==val) return false;
        }
    }
    return true;
}
bool solve(int ind){
    if (ind==clear.size()) {
        for (int i=1; i<=9; i++){
            for (int j=1; j<=9; j++) putchar(arr[i][j]);
            putchar('\n');
        }
        return true;
    }
    for (char val = '1'; val<='9'; val++){
        if (check(clear[ind].first, clear[ind].second, val)){
            arr[clear[ind].first][clear[ind].second] = val;
            if (solve(ind+1)) return true;
            arr[clear[ind].first][clear[ind].second] = '0';
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i=1; i<=9; i++){
        for (int j=1; j<=9; j++){
            int c = getchar();
            if (c>='1' && c<='9') arr[i][j] = c;
            else clear.push_back({i, j});
        }
        getchar();
    }

    solve(0);

    return 0;
}