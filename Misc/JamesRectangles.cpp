// Jame's Rectangles
// TODO: takes into consideration rectagnles that are not perpendicular to x and y axis

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, ans = 0;
set<pii> s;
vector<pii> v;
void print(pii a){
    cout << '(' << a.first << ", " << a.second << ") ";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, y});
        s.insert({x, y});
    }

    sort(v.begin(), v.end());
    cout << '\n';
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (v[i].first == v[j].first || v[i].second == v[j].second)
                continue;
            if (s.count({v[i].first, v[j].second}) && s.count({v[j].first, v[i].second})){
                print(v[i]);
                print(v[j]);
                print({v[i].first, v[j].second});
                print({v[j].first, v[i].second});
                cout << '\n';
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}