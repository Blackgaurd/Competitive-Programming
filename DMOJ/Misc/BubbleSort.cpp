// Bubble Sort

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;
using qpii = queue<pair<int, int>>;

int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (auto num: arr) cout << num << " ";
    cout << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                for (auto num: arr) cout << num << " ";
                cout << endl;
            }
        }
    }
    return 0;
}