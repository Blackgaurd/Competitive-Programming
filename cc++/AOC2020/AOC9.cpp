#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 1000 numbers
vector<ll> nums;
ll ttl;
bool check(ll x, vector<ll> arr){
    for (int i=0; i<24; i++){
        for (int j=i+1; j<25; j++){
            //cout << arr[i] << " " << arr[j] << endl;
            if (arr[i]+arr[j]==x) return true;
        }
    }
    return false;
}

int main(){
    nums.push_back(-1);
    for (int i=0; i<1000; i++){
        ll n; cin >> n;
        nums.push_back(n);
    }
    for (int i=26; i<=1000; i++){
        vector<ll> tmp;
        for (int j=i-1; j!=i-26; j--){
            tmp.push_back(nums[j]);
        }
        //for (auto t: tmp) cout << t << " ";
        //cout << endl;
        if (!check(nums[i], tmp)){
            ttl = nums[i];
            break;
        }
    }
    cout << ttl << endl;
    for (int start=1; start<=999; start++){
        ll sum = nums[start]; vector<ll> tmp;
        tmp.push_back(nums[start]);
        for (int nxt=start+1; nxt<=1000; nxt++){
            sum+=nums[nxt];
            tmp.push_back(nums[nxt]);
            if (sum>ttl) break;
            if (sum==ttl){
                sort(tmp.begin(), tmp.end());
                for (auto t: tmp) cout << t << " ";
                cout << endl;
                break;
            }
        }
    }
}

