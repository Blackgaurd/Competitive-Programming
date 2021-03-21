// USACO 2020 December Bronze P2- Daisy Chains

#include<bits/stdc++.h>
using namespace std;

int n, arr[105], psa[105];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    //sort(arr, arr+n);
    psa[0] = 0;
    int sol = n;
    for (int i=1; i<=n; i++) psa[i] = psa[i-1]+arr[i];
    for (int i=1; i<=n-1; i++){
        for (int j=i+1; j<=n; j++){
            int sum = psa[j]-psa[i-1], div = j-i+1;
            int avg = (sum%div==0?sum/div:0);
            if (avg){
                //cout << i << " - " << j << ": " << avg << endl;
                for (int k=i; k<=j; k++){
                    if (arr[k]==avg) {sol++; break;}
                }
            }
        }
    }
    cout << sol << '\n';

    return 0;
}