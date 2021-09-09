// FizzCoke

#include<bits/stdc++.h>
using namespace std;

const int MM = 1e5+3;
int n, m;
string w[MM];
vector<int> ans[MM];
set<int> nums;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    while (m--){
        int a; string b;
        cin >> a >> b;
        nums.insert(a);
        w[a] = b;
    }
    for (int i: nums)
        for (int j=i; j<=n; j+=i)
            ans[j].push_back(i);

    for (int i=1; i<=n; i++){
        if (ans[i].empty()) cout << i << '\n';
        else {
            for (int k: ans[i]) cout << w[k];
            cout << '\n';
        }
    }

    return 0;
}