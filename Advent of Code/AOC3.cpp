// 

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

// 323 tall, 31 wide
// (1,1) ()
char arr[330][35];
int a1[] = {1,3,5,7,1}, b1[] = {1,1,1,1,2};
ll sum = 1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    for (int i=0; i<323; i++){
        for (int j=0; j<31; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0; i<5; i++){
        int r = 0, c = 0, tree = 0;
        while (r<323){
            c+=a1[i]; c%=31;
            r+=b1[i]; 
            //cout << c << " " << r << " " << arr[r][c] << nl;
            if (arr[r][c]=='#') tree++;
        }
        cout << tree << nl;
        sum*=tree;
    }
    cout << sum << nl;
    

    return 0;
}