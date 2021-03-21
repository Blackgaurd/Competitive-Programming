// Connected Components

#include<bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

int n, p[1003];
vector<int> sets[1003];
int flead(int x){
    if (p[x]!=x) p[x] = flead(p[x]);
    return p[x];
}
bool comp(vector<int> a, vector<int> b){
    if (a.size()==0) return true;
    if (b.size()==0) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a[0]<b[0];
}
int main(){
    sc(n);
    for (int i=1; i<=n; i++) p[i] = i;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            int a; sc(a);
            if (a){
                if (flead(i)!=flead(j)){
                    p[flead(i)] = flead(j);
                }
            }
        }
    }
    for (int i=1; i<=n; i++){
        sets[p[i]].push_back(i);
    }
    sort(sets, sets+n, comp);
    for (int i=1; i<=n; i++){
        if (sets[i].size()){
            for (int num: sets[i]) cout << num << ' ';
            cout << '\n';
        }
    }

    return 0;
}