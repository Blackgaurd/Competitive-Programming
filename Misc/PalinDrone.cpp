// PalinDrone

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

ll arr[] = {0, 9, 18, 108, 198, 1098, 1998, 10998, 19998, 109998, 199998, 1099998, 1999998, 10999998, 19999998, 109999998, 199999998, 99999998, 999999998};
string t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    if (t.size()<=2 && stoi(t)<18){
        cout << arr[stoi(t)] << nl;
    }
    else cout << arr[18] << nl;
    
    return 0;
}
