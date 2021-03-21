// 

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

int n, letters[27], letters2[27], mode = 0, cnt = 0;
set<int> arr[100005], arr2[100005];
string t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    cin >> n >> t;
    arr[0].insert(t[0]);
    for (int i=1; i<n; i++){
        arr[i]=arr[i-1];
        arr[i].insert(t[i]);
    }
    arr2[n-1].insert(t[n-1]);
    for (int i=n-2; i>=0; i--){
        arr2[i] = arr2[i+1];
        arr2[i].insert(t[i]);
    }
    for (int i=0; i<n; i++){
        int tmp = min(arr[i].size(), arr2[i].size());
        letters[tmp]++;
    }
    for (int i=1; i<=26; i++){
        if (letters[i]>=cnt){
            mode = i;
            cnt = letters[i];
        }
    }
    cout << mode;


    return 0;
}