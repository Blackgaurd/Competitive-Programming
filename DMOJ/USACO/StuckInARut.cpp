//

#include<bits/stdc++.h>
using namespace std;

const int MM = 1e9+5;
int n, sols[51], block[51];
map<int, pair<int, int>> north, east;
bool comp1(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.second.first<b.second.first;
}
bool comp2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.second.second<b.second.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        char c; int a, b;
        cin >> c >> a >> b;
        if (c=='N'){
            north.insert({i, {a, b}});
        }
        else if (c=='E'){
            east.insert({i, {a, b}});
        }
    }
    sort(north.begin(), north.end(), comp1);
    sort(east.begin(), east.end(), comp2);
    


    return 0;
}