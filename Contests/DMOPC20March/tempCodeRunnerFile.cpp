// DMOPC '20 Contest 4 P1 - Missing Numbers

#include<bits/stdc++.h>
using namespace std;
#define ull long long
#define wt(x) cout << (#x) << ": " << (x) << '\n'

int t, n, s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> s;
        ull ttl = n * (n+1) / 2;
        ttl -= s;
        ull bot = ttl - n;
        if (bot < 0){
            bot = ttl - 1;
            cout << (bot / 2) << '\n';
        }
        else cout << (n - bot + 1) / 2 << '\n';
    }

    return 0;
}