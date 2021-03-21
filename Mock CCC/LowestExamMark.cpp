// Lowest Exam Mark

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int a, b, c;
    bool m = false;
    cin >> a >> b >> c;
    for (int i=0; i<=100; i++){
        if (round((a*(100-c)+c*i)*0.01)==b){
            cout << i;
            m = true;
            break;
        }
    }
    if (!m) cout << "DROP THE COURSE";

    return 0;
}