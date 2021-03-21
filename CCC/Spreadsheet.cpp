// CCC '04 S3 - Spreadsheet

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define ms memset
#define pb push_back
#define nl "\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll, ll>;
using qi = deque<int>;
using qpii = deque<pii>;

string arr[11][10];
int val[11][10] = {{0}};
bool def[11][10]; // defined (is there a num)

bool is_num(const string &str){
    return str.find_first_not_of("1234567890") == string::npos;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    for (int i=1; i<=10; i++){
        for (int j=1; j<=9; j++){
            string t; cin >> t;
            if (is_num(t)) {def[i][j] = true; val[i][j] = stoi(t);}
            arr[i][j] = t;
        }
    }
    /*for (int i=1; i<=10; i++){
        for (int j=1; j<=9; j++){
            cout << def[i][j] << " ";
        } cout << nl;
    }*/
    for (int i=1; i<=10; i++){
        for (int j=1; j<=9; j++){
            if (!def[i][j]){
                for (int pos = 0; pos<=arr[i][j].length(); i+=3) cout << arr[i][j][pos] << arr[i][j][pos+1] << nl;
            }
        }
    }

    return 0;
}