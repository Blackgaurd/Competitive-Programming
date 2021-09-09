// Bob's Median Student

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;

int n;
vector<pis> arr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        string t; int a;
        cin >> t >> a;
        arr.emplace_back(a, t);
    }
    sort(arr.begin(), arr.end());
    cout << arr[n/2 - (n+1)%2].second << '\n';

    return 0;
}