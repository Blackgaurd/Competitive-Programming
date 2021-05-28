// DMOPC '20 Contest 4 P2 - Beautiful Grids

#include<bits/stdc++.h>
using namespace std;
#define even false
#define odd true

// subtask 1
long long n, m, k;
unordered_map<long long, bool> row, col;
vector<long long> rodd, codd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i=0; i<k; i++){
        int a, b; cin >> a >> b;
        row[a] ^= 1;
        col[b] ^= 1;
    }
    for (auto &p: row){
        if (p.second){
            rodd.push_back(p.first);
        }
    }
    for (auto &p: col){
        if (p.second){
            codd.push_back(p.first);
        }
    }
    cout << max(rodd.size(), codd.size()) << '\n';
    while (!codd.empty() && !rodd.empty()){
        cout << rodd.back() << ' ' << codd.back() << '\n';
        rodd.pop_back(); codd.pop_back();
    }
    while (!rodd.empty()){
        cout << rodd.back() << ' ' << 1 << '\n';
        rodd.pop_back();
    }
    while (!codd.empty()){
        cout << codd.back() << ' ' << 1 << '\n';
        codd.pop_back();
    }



    return 0;
}