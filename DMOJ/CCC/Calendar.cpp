// CCC '00 J1 - Calendar

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string days[] = {"  1","  2","  3","  4","  5","  6","  7","  8","  9"," 10"," 11"," 12"," 13"," 14"," 15"," 16"," 17"," 18"," 19"," 20"," 21"," 22"," 23"," 24"," 25"," 26"," 27"," 28"," 29"," 30"," 31"};
    int n, d;
    cin >> n >> d;
    cout << "Sun Mon Tue Wed Thr Fri Sat\n";
    for (int i=0; i<n-1; i++) {cout << "    ";}
    for (int i=0; i<d; i++){
        cout << days[i];
        if (n==7 || i==d-1){
            n=0;
            cout <<  "\n";
        }
        else cout << " ";
        n++;
    }
    cout << "\n\n";

    return 0;
}