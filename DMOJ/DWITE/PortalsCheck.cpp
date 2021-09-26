// DWITE '11 R2 #5 - Portals Check

#include<bits/stdc++.h>
using namespace std;

const int MM = 1e5+3;
int n;
struct qry{ char c; int from, to; } q[MM];
unordered_map<string, int> val;
int p[MM];
int flead(int __x){
    if (p[__x]!=__x) p[__x] = flead(p[__x]);
    return p[__x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cases = 5;
    while (cases--){
        cin >> n;
        for (int i=0; i<n; i++){
            char c; string a, b;
            cin >> c >> a >> b;
            if (!val[a]){
                val[a] = val.size() + 1;
            }
            if (!val[b]){
                val[b] = val.size() + 1;
            }
            q[i].c = c;
            q[i].from = val[a];
            q[i].to = val[b];
        }
        for (int i=1; i<=val.size()+1; i++){
            p[i] = i;
        }
        for (int i=0; i<n; i++){
            int from = flead(q[i].from), to = flead(q[i].to);
            if (q[i].c == 'p'){
                if (from != to){
                    p[from] = to;
                }
            }
            else {
                if (from != to) printf("not ");
                printf("connected\n");
            }
        }
    }
    return 0;
}