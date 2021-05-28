// DMPG '18 G1 - Musical Chairs

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, k;
vector<pair<int, int>> arr;
vector<int> open;
int main(){
    sc(n); sc(k);
    for (int i=0; i<k; i++){
        int a; sc(a);
        open.push_back(a);
    }
    for (int i=1; i<=n; i++){
        int a; sc(a);
        arr.push_back({a, i});
    }
    sort(arr.begin(), arr.end());
    for (int i=0; i<n; i++){
        
    }

    return 0;
}