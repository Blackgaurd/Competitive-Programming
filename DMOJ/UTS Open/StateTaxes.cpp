// UTS Open '21 P5 - State Taxes

#include<bits/stdc++.h>
using namespace std;

long long n, q, sal[10003], rev[10003];
int main(){
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> sal[i];
    for (int e=0; e<q; e++){
        long long c, l, r, x;
        cin >> c >> l >> r;
        if (c==1){
            cin >> x;
            for (int j=l; j<=r; j++) sal[j]+=x;
        }
        else if (c==2)
            for (int j=l; j<=r; j++)
                rev[j]+=sal[j];
    }
    for (int i=1; i<=n; i++) cout << rev[i] << ' ';
    cout << '\n';

    return 0;
}