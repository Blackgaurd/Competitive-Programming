// DWITE '06 R5 #5 - Prime Palindromes

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ms memset
#define pb push_back
#define nl "\n"
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = deque<int>;

set<int> primepali;
bool prime(int num){
    if (num%2==0) return false;
    for (int i=3; i<=sqrt(num); i+=2){
        if (num%i==0) return false;
    }
    return true;
}
void gen(string num, int cap){
    int tmp = stoi(num);
    if (prime(tmp)) {
        primepali.insert(tmp);
    }
    if (num.size()==cap) return;
    for (char c='0'; c<='9'; c++){
        gen(c+num+c, cap);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    primepali.insert(2);
    for (int i=0; i<=9; i++){
        gen(to_string(i), 5);
    }
    for (int i=11; i<=99; i+=11){
        gen(to_string(i), 4);
    }
    for (auto it: primepali) cout << it << ", ";
    // sample input has 3, test case has 5
    /*for (int k=0; k<3; k++){
        int a, b, cnt=0; scan(a); scan(b);
        for (auto n: primepali){
            if (n>=a && n<=b) cnt++; 
        }
        cout << cnt << nl;
    }*/


    return 0;
}