// DMOPC '20 Contest 3 P2 - Bob and Parallel-Ks

#include<bits/stdc++.h>
using namespace std;

#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, m, k, ans = 0;
vector<vector<unsigned long long>> arr;
int check(vector<unsigned long long> a, vector<unsigned long long> b){
    int ret = 0;
    for (int i=2; i<=n; i++){
        if (a[0]+n*k<b[0]+n*k) continue;
        if (a[i]+k==b[i] && a[i-1]+k==b[i-1]) ret++;
        else if (a[i]-k==b[i] && a[i-1]-k==b[i-1]) ret++;
    }
    return ret;
}
int main(){
    sc(m); sc(n); sc(k);
    for (int i=0; i<m; i++){
        vector<unsigned long long> tmp = {0};
        for (int j=0; j<n; j++){
            unsigned long long a; sc(a);
            tmp.push_back(a);
            tmp[0]+=a;
        }
        arr.push_back(tmp);
    }
    for (int i=0; i<m-1; i++){
        for (int j=i+1; j<m; j++){
            ans+=check(arr[i], arr[j]);
        }
    }
    cout << ans << '\n';
}