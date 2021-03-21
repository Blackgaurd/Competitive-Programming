// 

#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"


int n; string t;
bool check(int dis){
    string copy = t;
    int cows = 0;
    for (int i=0; i<n; i++){
        if (t[i]=='1'){
            for (int j=1; j<dis; j++){
                if (i+j<n && copy[i+j]=='0') copy[i+j]='x';
                if (i-j>=0 && copy[i-j]=='0') copy[i-j]='x';
            }
        }
    }
    for (int i=0; i<n; i++){
        if (copy[i]=='0'){
            for (int j=1; j<dis; j++){
                if (i+j<n && copy[i+j]=='0') copy[i+j]='x';
                if (i-j>=0 && copy[i-j]=='0') copy[i-j]='x';
            }
            cows++;
        }
        if (cows>=2) return true;
    }
    //cout << dis << " " << cows << nl;
    return false;
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    
    cin >> n >> t;
    //t = "0"+t+"0";
    int hi = n-1, lo = 1, ans = 0;
    while (hi>=lo){
        int mid = (lo+hi)/2;
        if (check(mid)){ans=mid; lo = mid+1;}
        else hi = mid-1;
    }
    cout << ans << nl;

    return 0;
}