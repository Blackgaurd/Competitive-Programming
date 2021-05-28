// Mock CCC '20 Contest 1 J1 - A Rage Tree Problem

#include<bits/stdc++.h>
using namespace std;

int arr[4];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0; i<4; i++){
        cin >> arr[i];
    }
    sort(arr, arr+4);
    cout << arr[0] << '\n' << arr[3];
}