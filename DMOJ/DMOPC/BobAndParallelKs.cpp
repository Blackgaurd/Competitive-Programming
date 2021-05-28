// DMOPC '20 Contest 3 P2 - Bob and Parallel-Ks
// flawed but whatever

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, m, k, ind = 1, ans = 0;
vector<int> counts[200003][23];
vector<vector<int>> arr;

bool comp(vector<int> &a, vector<int> &b){
    return a[ind]<b[ind];
}
int check(vector<int> a, vector<int> b){
    int ret = 0;
    for (int i=2; i<=n; i++){
        if (a[i]+k==b[i] && a[i-1]+k==b[i-1]) ret++;
        else if (a[i]-k==b[i] && a[i-1]-k==b[i-1]) ret++;
    }
    return ret;
}
int main(){
    sc(m); sc(n); sc(k);
    if (m==1) {cout << 0 << '\n'; return 0;}
    for (int i=0; i<m; i++){
        vector<int> tmp = {i};
        for (int j=0; j<n; j++){
            int a; sc(a);
            tmp.push_back(a);
        }
        arr.push_back(tmp);
    }
    if (m<=1){
        for (int i=0; i<m-1; i++){
            for (int j=i+1; j<m; j++){
                ans+=check(arr[i], arr[j]);
            }
        }
    }
    else{
        //cout << '\n';
        for (; ind<=n; ind++){
            sort(arr.begin(), arr.end(), comp);
            for (int i=0; i<m-1; i++){
                for (int j=i+1; j<m; j++){
                    if (arr[i][ind]+k==arr[j][ind]){
                        counts[arr[i][0]][arr[j][0]].push_back(ind);
                    }
                    else if (arr[i][ind]+k<arr[j][ind]) break;
                }
            }
        }
        for (int i=0; i<m; i++){
            for (int j=0; j<m; j++){
                for (int num=1; num<counts[i][j].size(); num++){
                    if (counts[i][j][num]-1==counts[i][j][num-1]) 
                        ans++;
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}