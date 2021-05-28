// WC '18 Finals J1 - Conditional Contracts

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, mx[2];
unordered_map<long long, int> mp;
int main(){
    sc(n);
    while (n--){
        long long a; sc(a);
        mp[a]++;
    }
    for (auto p: mp){
        int cnt = p.second;
        if (cnt>mx[0]){
            mx[1] = mx[0];
            mx[0] = cnt;
        }
        else if (cnt>mx[1]){
            mx[1] = cnt;
        }
    }
    cout << (mx[0]+mx[1]) << '\n';

    return 0;
}