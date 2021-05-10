// Bob's Maximal Sequence Sum

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

int n, a[100005], b[100005], sum = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    scan(n);
    for (int i=1; i<n; i++) scan(b[i]);
    a[0] = b[1];
    for (int i=1; i<n; i++){
        if (a[i-1]>b[i]) a[i-1] = b[i];
        a[i] = b[i];
    }
    for (int i=0; i<n; i++) sum+=a[i];
    cout << sum;

    return 0;
}