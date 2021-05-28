// CCO '98 P1 - Fibonacci Numbers

#include<bits/stdc++.h>
using namespace std;

unordered_map<int, string> fib;

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

void generate(){
    fib.insert(make_pair(1 ,"1"));
    fib.insert(make_pair(2, "1"));
    for (int i=3; i<=200; i++){
        string n = add(fib[i-1], fib[i-2]);
        fib.insert(make_pair(i, n));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    generate();
    while (true){
        int a; cin >> a;
        if (!a) break;
        cout << fib[a] << '\n';
    }
}