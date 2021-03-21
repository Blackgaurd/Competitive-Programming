//

#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define nl "\n"

int n, q;
map<string, string> nums, names;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    scan(n); scan(q);
    for (int i=0; i<n; i++){
        string a, b; cin >> a >> b;
        nums[a]=b; names[b]=a;
    }
    for (int i=0; i<q; i++){
        string a, b; cin >> a >> b;
        if (a=="phone"){
            cout << nums[b] << nl;
        }
        else if (a=="name") cout << names[b] << nl;
    }

    return 0;
}