// Disjoint Set Test
// Using Kruskal this time

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;
using pii = pair<int, int>;

const int MM = 1e5+5;
int n, m, p[MM];
vector<int> ans;
int flead(int x){
    if (p[x]!=x) p[x] = flead(p[x]);
    return p[x];
}
int main(){
    sc(n); sc(m);
    for (int i=1; i<=n; i++) p[i] = i;
    for (int i=1; i<=m; i++){
        int a, b; sc(a); sc(b);
        if (flead(a)!=flead(b)){
            ans.push_back(i);
            p[flead(a)] = flead(b);
        }
    }
    if (ans.size()==n-1){
        for (int i: ans) cout << i << '\n';
    }
    else cout << "Disconnected Graph\n";


    return 0;
}