// CCC '09 J3 - Good Times

#include<bits/stdc++.h>
using namespace std;

int n;
void bal(){if (n>=2400) n-=2400; else if (n<0) n+=2400;}
int main(){
    cin >> n;
    cout << n << " in Ottawa\n";
    n-=300; bal();
    cout << n << " in Victoria\n";
    n+=100; bal();
    cout << n << " in Edmonton\n";
    n+=100; bal();
    cout << n << " in Winnipeg\n";
    n+=100; bal();
    cout << n << " in Toronto\n";
    n+=100; bal();
    cout << n << " in Halifax\n";
    n+=30; bal(); if (n%100>=60){n+=40;}
    cout << n << " in St. John's\n";

    return 0;
}