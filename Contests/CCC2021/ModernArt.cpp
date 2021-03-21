// Brute Force (subtask 3)

#include<bits/stdc++.h>
using namespace std;

int n, m, k, gold;
bool row[5000003], col[5000003];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for (int i=0; i<k; i++){
        char c; int a;
        cin >> c >> a;
        if (c=='R') row[a] ^= 1;
        else col[a] ^= 1;
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (row[i] + col[j] == 1) gold++;
        }
    }
    
    cout << gold << '\n';
    
}