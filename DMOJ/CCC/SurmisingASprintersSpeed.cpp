// CCC '20 S1 - Surmising a Sprinter's Speed

#include <bits/stdc++.h>
using namespace std;
#define m second
#define t first

int n;
double ans = 0;
vector<pair<double, double>> arr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--){
        double a, b; cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    for (int i=0; i<arr.size()-1; i++){
        pair<double, double> a = arr[i], b = arr[i+1];
        double speed = abs((double)(a.m-b.m)/(double)(a.t-b.t));
        ans = max(ans, speed);
    }
    cout << ans << '\n';

    return 0;
}