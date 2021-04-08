// ICPC PACNW 2016 A - Alphabet

#include<bits/stdc++.h>
using namespace std;

string t;
vector<char> lis = {'0'};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    for (char c: t){
        if (c > lis.back()) lis.push_back(c);
        else if (c != lis.back())
            *lower_bound(lis.begin(), lis.end(), c) = c;
    }
    cout << 27 - lis.size() << '\n';

    return 0;
}