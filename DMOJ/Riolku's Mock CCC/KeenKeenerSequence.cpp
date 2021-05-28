// Riolku's Mock CCC S2 - Keen Keener Sequence
// brute force first

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n; 
long long arr[1503], ans = 0;
unordered_map<long long, vector<pii>> mult;
bool distinct(pii a, pii b){
    if (a.first == b.first) return false;
    if (a.first == b.second) return false;
    if (a.second == b.first) return false;
    if (a.second == b.second) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    if (n<=400){
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                for (int k=j+1; k<n; k++){
                    for (int l=k+1; l<n; l++){
                        if (arr[i] * arr[j] == arr[k] * arr[l]) ans++;
                        if (arr[i] * arr[k] == arr[j] * arr[l]) ans++;
                        if (arr[i] * arr[l] == arr[j] * arr[k]) ans++;
                    }
                }
            }
        }
    }
    else {
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                long long ind = arr[i] * arr[j];
                for (pii tup: mult[ind]){
                    if (distinct({i, j}, tup)) {ans++;}
                }
                
                mult[ind].push_back({i, j});
            }
        }
    }
    ans<<=3;
    cout << ans << '\n';

    return 0;
}