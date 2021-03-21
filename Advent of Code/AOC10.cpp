#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

// official test case: 100
// test case 1: 11
// test case 2: 31

int o = 0, tw = 0, tr = 0, m = 0;
long long cnt = 0;
vector<int> arr;
// naive approach
void solve(vector<int> nums, int start){
    if (nums.size()==2) return;
    for (int i=start; i<=nums.size()-2; i++){
        if (nums[i+1]-nums[i-1]<=3){
            cnt++;
            int tmp = nums[i];
            nums.erase(nums.begin()+i);
            solve(nums, i);
            nums.insert(nums.begin()+i, tmp);
        }
    }
    return;
}

int main(){ 
    for (int i=0; i<100; i++){
        int a; cin >> a;
        arr.push_back(a);
        m = max(m, a);
    }
    arr.push_back(m+3); arr.push_back(0);
    sort(arr.begin(), arr.end());
    cout << nl;
    for (auto i: arr) cout << i << " ";
    cout << nl << nl;
    // part 1
    /*for (int i=1; i<102; i++){
        if (arr[i]-arr[i-1]==1) o++;
        else if (arr[i]-arr[i-1]==3) tr++;
        else if (arr[i]-arr[i-1]==2) tw++;
    }
    cout << o << " " << tw << " " << tr << nl;
    */
   // solve(arr, 1);
   vector<vector<int>> combs;
   vector<int> temp;
   for (int i=0; i<arr.size()-1; i++){
       if (arr[i+1]-arr[i]==3){

           combs.push_back(temp);
           temp.clear();
       }
       else {
           temp.push_back(arr[i]);
       }
   }
   for (auto i: combs) {
       for (auto it: i) cout << it << " ";
       cout << nl;
   }
   cout << nl << "count: " << cnt << nl;
   int n[] = {4,4,7,7,2,7,7,2,7,2,7,2,7,7,7,7,7,7,7};
   unsigned long long sol = 1;
   for (auto i: n) sol*=i;
   cout << sol << nl;

    return 0;
}