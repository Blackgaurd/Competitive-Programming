// BlueBook - Mode

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int x, arr[105] = {0}, count = 0;
    do{
        cin >> x;
        arr[x]++;
    } while (x!=-1);
    for(int i=1; i<=100; i++){
        if (arr[i]>=count){
            count = arr[i];
        }
    }

    for(int i=1; i<=100; i++){
        if (arr[i]==count){
            cout << i << endl;
        }
    }

    return 0;
}