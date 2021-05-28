// Largest Minimum Distance

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = deque<int>;
using qpii = deque<pii>;

const int MM = 1e5+5;
int n, m, arr[MM];

bool check(int x){
    int cnt = 1, prev = arr[1];
    for (int i=2; i<=n; i++){
        if (arr[i]-prev>=x){cnt++; prev = arr[i];}
    }
    return cnt>=m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> arr[i];
    sort(arr+1, arr+n+1);
    int lo = 1, hi = arr[n]-arr[1], ans = 0;
    while (lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid)){ans = mid; lo = mid+1;}
        else hi = mid-1;
    }
    cout << ans;

    return 0;
}