// CCC '06 S1 - Maternity

#include<bits/stdc++.h>
using namespace std;
int x;
string a, b;
bool genes[6][2];
bool check(string baby){
    int pass = 0;
    for (int i=0; i<10; i+=2){
        if (a[i]==b[i] && baby[i/2]==a[i]) pass++;
        else if (a[i+1]==b[i+1] && baby[i/2]==a[i+1]) pass++;
    }
    return pass==5;
}
int main(){
    cin >> a >> b >> x;
    while (x--){
        string baby; cin >> baby;
        cout << check(baby) << '\n';
    }
}