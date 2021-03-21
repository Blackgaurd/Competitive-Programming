// Mock CCC '20 Contest 1 J4 - A Binary Problem

#include<bits/stdc++.h>
using namespace std;

const int MM = 1e6;
int n, pre[MM], post[MM];
long long ans = 0;
string t;
int main(){
    cin >> n >> t;
    int start = 0;
    while (t[start]=='0') {pre[start] = INT_MAX; start++;}
    for (int i=start; i<n; i++){
        if (t[i]=='1') pre[i] = 0;
        else pre[i] = pre[i-1]+1;
    }
    start = n-1;
    while (t[start]=='0') {post[start] = INT_MAX; start--;}
    for (int i=start; i>=0; i--){
        if (t[i]=='1') post[i] = 0;
        else post[i] = post[i+1]+1;
    }
    for (int i=0; i<n; i++) ans+=min(pre[i], post[i]);
    cout << ans << '\n';
}