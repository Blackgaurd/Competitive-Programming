// CCC '10 S1 - Computer Purchase

#include<bits/stdc++.h>
using namespace std;

int n;
struct tup{
    string t;
    int r, s, d;
} arr[10000];
bool cmp(tup a, tup b){
    int va = 2 * a.r + 3 * a.s + a.d;
    int vb = 2 * b.r + 3 * b.s + b.d;
    if (va == vb) return a.t < b.t;
    return va > vb;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i].t >> arr[i].r >> arr[i].s >> arr[i].d;
    }
    sort(arr, arr+n, cmp);
    for (int i=0; i<2; i++){
        cout << arr[i].t << '\n';
    }

    return 0;
}