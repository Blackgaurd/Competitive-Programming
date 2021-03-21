// Maximum Sum

#include<bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, ans = 0;
vector<int> nums;
int main(){
    scan(n);
    for (int i=0; i<n; i++){
        int a; scan(a);
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end(), greater<>());
    for (int i=0; i<n; i+=2) ans+=nums[i];
    cout << ans << '\n';
    
}