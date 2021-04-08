// AOC 2020 1

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using vi = vector<int>;

vi arr;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    while (true){
        int n; cin >> n;
        arr.pb(n);
        if (n==1741) break;
    }
    for (int i=0; i<198; i++){
        for (int j=i+1; j<199; j++){
            for (int k=j+1; k<200; k++){
                if (arr[i]+arr[j]+arr[k]==2020) {cout << arr[i]*arr[j]*arr[k]; break;}
            }

        }
    }

    return 0;
}