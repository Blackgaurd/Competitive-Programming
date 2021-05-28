// Factorial Sum List

#include<bits/stdc++.h>
using namespace std;

int arr[10];
int n;
int solve(int x){
    int sum = 0;
    while (x){
        int mod = x%10;
        sum+=arr[mod];
        x/=10;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    arr[0] = arr[1] = 1;
    for (int i=2; i<=9; i++) arr[i] = arr[i-1]*i;
    while (true){
        cin >> n;
        if (!n) break;
        set<int> nums;
        nums.insert(n);
        while (true){
            n = solve(n);
            if (nums.count(n)) break;
            nums.insert(n);
        }
        cout << nums.size()+1 << '\n';
    }

    return 0;
}