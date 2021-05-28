// BlueBook - Min

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    float x, m = 1001;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x;
        m = min(m, x);
    }
    printf("%.2f", m);

    return 0;
}