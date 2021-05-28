// Binary

#include<bits/stdc++.h>
using namespace std;

int n;
string tbin(int x){
    if (!x) return "0000";
    string ret = "";
    while (x){
        ret = to_string(x%2) + ret;
        x/=2;
    }
    while (ret.size()%4){
        ret = "0" + ret;
    }
    return ret;
}
string space[] = {"", "", "", " "};
int main(){
    cin >> n;
    while (n--){
        int a; cin >> a;
        string bin = tbin(a);
        for (int i=0; i<bin.size(); i++){
            cout << bin[i] << space[i%4];
        }
        cout << '\n';
    }
}