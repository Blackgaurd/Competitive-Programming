// USACO 2020 December Bronze P1 - Do You Know Your ABCs?

#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i=0; i<7; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    cout << arr[0] << " " << arr[1] << " " << arr[6]-arr[0]-arr[1] << '\n';

    return 0;
}