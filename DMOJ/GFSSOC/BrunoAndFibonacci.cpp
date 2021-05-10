// Bruno And Fibonacci

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
using qi = queue<int>;
using qpii = queue<pii>;
#define ms memset;

unordered_map<int, int> nums;
int fib(int n){
    if (n<=1) return 1;
    if (nums.find(n)!=nums.end()) return nums[n];
    nums[n] = (fib((n-1)/2)*fib((n-2)/2)+fib(n/2)*fib((n+1)/2));
    return nums[n];
}
int fibnums[501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s; 
    getline(cin, s);
    fibnums[1] = true;
    for (int i=2; i<14; i++) {
        if (fib(i)<=n) fibnums[fib(i)] = true;
    }
    for (int i=1; i<=s.length(); i++){
        if (s[i-1]=='A'){
            if (!fibnums[i]){
                cout << "Bruno, GO TO SLEEP";
                return 0;
            }
        }
    }
    cout << "That's quite the observation!";
    

    return 0;
}