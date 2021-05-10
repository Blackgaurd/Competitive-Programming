// A Plus B (Hard)
// input numbers as strings

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

string add(string num1, string num2){
    if(num1.size() < num2.size()) swap(num1, num2);

    int j = num1.size()-1;
    for(int i=num2.size()-1; i>=0; i--, j--) num1[j]+=(num2[i]-'0');

    for(int i=num1.size()-1; i>0; i--){
        if(num1[i] > '9'){
            int d = num1[i]-'0';
            num1[i-1] = ((num1[i-1]-'0') + d/10) + '0';
            num1[i] = (d%10)+'0';
        }
    }
    if(num1[0] > '9'){
        string k;
        k+=num1[0];
        num1[0] = ((num1[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        num1 = k+num1;
    }
    return num1;
}
bool isSmaller(string num1, string num2){
    int n1 = num1.length(), n2 = num2.length();
    if (n1 < n2) return true;
    if (n2 < n1) return false;
    for (int i = 0; i < n1; i++){
        if (num1[i] < num2[i]) return true;
        else if (num1[i] > num2[i]) return false;
    }
 
    return false;
}
string diff(string num1, string num2){
    if (isSmaller(num1, num2)) swap(num1, num2);
    string sol = "";
    int n1 = num1.size(), n2 = num2.size();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
 
    int carry = 0;
    for (int i = 0; i < n2; i++) {
        int sub = ((num1[i] - '0') - (num2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else carry = 0;
        sol+=(sub + '0');
    }
 
    for (int i = n2; i < n1; i++) {
        int sub = ((num1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else carry = 0;
        sol+=(sub + '0');
    }
    reverse(sol.begin(), sol.end());
    while (sol[0]=='0') sol = sol.substr(1, sol.size()-1);
    return sol;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    while (n--){
        string a, b; cin >> a >> b;
        bool aneg = a[0]=='-'? true:false, bneg = b[0]=='-'? true:false;
        if (aneg != bneg){
            // set the negative number to be a
            if (bneg) swap(a, b);
            a = a.substr(1, a.size()-1);
            // if abs(a) == abs(b)
            if (a==b) {cout << 0 << nl; continue;}
            // positive number > negative number
            if (isSmaller(a, b)) cout << diff(b, a) << nl;
            // negative number > positive number, results in negative 
            else cout << '-' << diff(a, b) << nl;
        }
        // a and b are negative
        else if (aneg && bneg){
            a = a.substr(1, a.size()-1);
            b = b.substr(1, b.size()-1);
            cout << '-' << add(a, b) << nl;
        }
        // a and b are positive
        else cout << add(a, b) << nl;
    }
}