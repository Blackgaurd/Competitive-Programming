// CCC '04 S1 - Fix

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int n;
bool comp(string &s1, string &s2){
    return s1.size() > s2.size();
}
bool check(string arr[]){
    sort(arr, arr + 3, comp);
    if (arr[2] == arr[0].substr(0, arr[2].size()))
        return false;
    if (arr[2] == arr[1].substr(0, arr[2].size()))
        return false;
    if (arr[2] == arr[0].substr(arr[0].size() - arr[2].size(), arr[2].size()))
        return false;
    if (arr[2] == arr[1].substr(arr[1].size() - arr[2].size(), arr[2].size()))
        return false;
    if (arr[1] == arr[0].substr(0, arr[1].size()))
        return false;
    if (arr[1] == arr[0].substr(arr[0].size() - arr[1].size(), arr[1].size()))
        return false;
    return true;
}
int main(){
    cin >> n;
    while (n--){
        string arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        cout << (check(arr) ? "Yes" : "No") << nl;
    }
}